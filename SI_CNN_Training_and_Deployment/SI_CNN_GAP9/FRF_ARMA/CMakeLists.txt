cmake_minimum_required(VERSION 3.16)

###############################################################################
# Application related definitions
###############################################################################
set(TARGET_NAME         FRF_multiclass_CNN)
set(MAIN                FRF_multiclass_CNN.c)

set(TRAINED_MODEL       ${CMAKE_CURRENT_SOURCE_DIR}/FRF_multiclass_CNN.onnx)
set(AT_MODEL_PATH       ${CMAKE_CURRENT_BINARY_DIR}/model_dir/model.c)
set(AT_TENSORS_DIR      ${CMAKE_CURRENT_BINARY_DIR}/tensors)
set(MODEL_EXPRESSIONS   ${CMAKE_CURRENT_BINARY_DIR}/model_dir/Expression_Kernels.c)



###############################################################################
# CMake pre initialization
###############################################################################
include($ENV{GAP_SDK_HOME}/utils/cmake/setup.cmake)

###############################################################################
# Autotiler Project Setup
###############################################################################
autotiler_add_model(
  TARGET_NAME FRF_multiclass_CNN
  MODEL_PATH ${AT_MODEL_PATH}
  MODEL_TENSORS_DIR ${AT_TENSORS_DIR}
  PRI1_USED TRUE
  PRI1_FLASH flash
  PRI1_FILENAME "L3_Flash_Const.dat"
  L1_MEMORY ${CONFIG_MODEL_L1_MEMORY}
  L2_MEMORY ${CONFIG_MODEL_L2_MEMORY}
  L3_MEMORY ${CONFIG_MODEL_L3_MEMORY}
  L2STATIC_MEMORY ${CONFIG_MODEL_L2STATIC_MEMORY}
  L3STATIC_MEMORY ${CONFIG_MODEL_L3STATIC_MEMORY})
###############################################################################
# Build autotiler model from ONNX/TFLite model using NNTOOL API
###############################################################################

add_custom_command(
    OUTPUT ${AT_MODEL_PATH} ${MODEL_EXPRESSIONS} ${AT_TENSORS_DIR}
    COMMENT "Generate the autotiler model, tensors and expressions code: ${AT_MODEL_PATH} ${MODEL_EXPRESSIONS} ${AT_TENSORS_DIR}"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/gen_FRF_multiclass_CNN_at_model.py ${TRAINED_MODEL}
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/gen_FRF_multiclass_CNN_at_model.py --at_model_path=${AT_MODEL_PATH} --tensors_dir=${AT_TENSORS_DIR} --trained_model=${TRAINED_MODEL}  --flash_type=${MODEL_L3_FLASH} --ram_type=${MODEL_L3_RAM}
)

add_custom_target(gen_model
    DEPENDS ${AT_MODEL_PATH} ${MODEL_EXPRESSIONS} ${AT_TENSORS_DIR}
)

add_custom_target(clean_model
  COMMENT "clean_model: removing ${AT_MODEL_PATH}"
  COMMAND rm -rf ${AT_MODEL_PATH} ${MODEL_EXPRESSIONS} ${AT_TENSORS_DIR}/*
)


###############################################################################
# Application dependencies
###############################################################################
list(TRANSFORM KERNEL_C PREPEND ${CONFIG_MODEL_BUILDDIR}/)
list(APPEND TARGET_SRCS ${MAIN}
                        ${CNN_LIB}
                        ${KERNEL_C}
                        ${MODEL_EXPRESSIONS}
)

list(APPEND TARGET_INCS ${CMAKE_CURRENT_SOURCE_DIR}
                        ${TILER_INC}
                        ${TILER_EMU_INC}
                        $ENV{GAP_SDK_HOME}/libs/gap_lib/include
                        $ENV{GAP_SDK_HOME}/utils/power_meas_utils
                        ${CNN_LIB_INCLUDE_NOPREPEND}
                        ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_MODEL_BUILDDIR}
                        ${CMAKE_CURRENT_SOURCE_DIR}
                        ${CMAKE_CURRENT_SOURCE_DIR}/model_dir
)

list(APPEND TARGET_CFLAGS   -O3)

math(EXPR FREQ_CL ${CONFIG_FREQUENCY_CLUSTER}/1000000 OUTPUT_FORMAT DECIMAL)
math(EXPR FREQ_FC ${CONFIG_FREQUENCY_FC}/1000000 OUTPUT_FORMAT DECIMAL)
math(EXPR FREQ_PE ${CONFIG_FREQUENCY_PERIPH}/1000000 OUTPUT_FORMAT DECIMAL)

message(STATUS "Clock speeds - Cluster ${FREQ_CL} FC ${FREQ_FC} Peripheral ${FREQ_PE}")
list(APPEND TARGET_PREPROCESSOR -DAT_MODEL_PREFIX=${MODEL_PREFIX}
                                -DSTACK_SIZE=${CONFIG_CL_MASTER_CORE_STACK_SIZE}
                                -DSLAVE_STACK_SIZE=${CONFIG_CL_SLAVE_CORE_STACK_SIZE}
                                -DFREQ_CL=${FREQ_CL}
                                -DFREQ_FC=${FREQ_FC}
                                -DFREQ_PE=${FREQ_PE}
)
LIST(APPEND TARGET_PREPROCESSOR -DPERF)




project(${TARGET_NAME} C ASM)

add_executable(${TARGET_NAME} ${TARGET_SRCS})
target_link_libraries(${TARGET_NAME} PUBLIC m)

target_compile_options(${TARGET_NAME} PUBLIC ${TARGET_CFLAGS} ${TARGET_PREPROCESSOR})
target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCS})

###############################################################################
# CMake post initialization
###############################################################################
setupos(${TARGET_NAME})
target_print_header(${TARGET_NAME})
target_print_option(STATUS ${TARGET_NAME} ${Cyan} "Include directories" "${TARGET_INCS}" ${Cyan})
target_print_compile_options(STATUS ${TARGET_NAME} ${Cyan})
target_print_footer(${TARGET_NAME})
