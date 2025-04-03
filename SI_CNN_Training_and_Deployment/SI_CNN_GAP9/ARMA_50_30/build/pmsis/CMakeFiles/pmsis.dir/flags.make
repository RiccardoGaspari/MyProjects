# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# compile ASM with /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc
# compile C with /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc
ASM_DEFINES = -DCONFIG_BOARD_GAP9EVK_V1_3 -DCONFIG_BOARD_GAP9MOD_V1_0_B -DCONFIG_DEVICE_TREE -DCONFIG_DRIVER_APS256XXN -DCONFIG_DRIVER_APS256XXN_AS_DEFAULT -DCONFIG_DRIVER_CLUSTERTEAM -DCONFIG_DRIVER_CRC32 -DCONFIG_DRIVER_DEFAULT_FLASH -DCONFIG_DRIVER_DEFAULT_RAM -DCONFIG_DRIVER_FLASH_API -DCONFIG_DRIVER_FLASH_PARTITION_V2=1 -DCONFIG_DRIVER_MRAM -DCONFIG_DRIVER_MX25U51245G -DCONFIG_DRIVER_MX25U51245G_AS_DEFAULT -DCONFIG_DRIVER_POWERSUPPLYGPIO -DCONFIG_DRIVER_POWERSUPPLY_API -DCONFIG_DRIVER_RAM_API -DPI_LOG_DEFAULT_LEVEL=PI_LOG_NONE -DUSE_FLASH_PARTITION_V2=1 -D__BSP_CRC__ -D__BSP_FLASH__ -D__BSP_POWERSUPPLY__ -D__BSP_RAM__

ASM_INCLUDES = -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/maestro/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i2s/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/efuse/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_core/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fc_event/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pad/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/gpio/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/ffc/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/perf/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/watchdog/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i2c/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i3c/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_datamove/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/spim/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_timeout/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_timestamp/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/dmacpy/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pwm/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/rtc/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/xip/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_hyperbus/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_octospi/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes_dual_core/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_cpi/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_csi2/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_uart/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_fifo/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_sdio/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/quiddikey/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/rtos/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/boards/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/buffer -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/crc32/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mram/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mx25u51245g/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/powersupplygpio/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/aps256xxn/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/include -I/home/rick/SI_CNN_GAP9/ARMA_50_30/build/devicetree/internal/include -I/home/rick/SI_CNN_GAP9/ARMA_50_30/build/devicetree/include -I/home/rick/SI_CNN_GAP9/ARMA_50_30/build/devicetree/fpv2/include -I/home/rick/gap_sdk_private/rtos/pmsis/include -I/home/rick/gap_sdk_private/libs/baselibs/printf -I/home/rick/gap_sdk_private/rtos/pmsis/tools/assert/include -I/home/rick/gap_sdk_private/rtos/pmsis/tools/allocator/include -I/home/rick/gap_sdk_private/gvsoc/gvsoc/include -I/home/rick/gap_sdk_private/rtos/pmsis/archi/chips/gap9/include -I/home/rick/gap_sdk_private/rtos/pmsis/archi/include -I/home/rick/gap_sdk_private/rtos/pmsis/archi/linker -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/pmsis/include -I/home/rick/gap_sdk_private/rtos/pmsis/api/timer -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/portable/GCC/RI5CY-GAP9 -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/libs/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/config -I/home/rick/gap_sdk_private/rtos/pmsis/api/include/chips/gap9 -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/include -I/home/rick/gap_sdk_private/rtos/pmsis/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/api/include/pmsis/rtos

ASM_FLAGS =  -x assembler-with-cpp -DASSEMBLY_LANGUAGE -Os -D__GAP__ -D__riscv__ -D__RISCV_ARCH_GAP__=1 -D__USE_TCDM_MALLOC__=1 -D__FC_MALLOC_NATIVE__=0 -D__L2_MALLOC_NATIVE__=0 -D__PMSIS_L2_MALLOC_NATIVE__=0 -DPMSIS_DRIVERS=1 -DFEATURE_CLUSTER -DGAP_SDK_VERSION=5.20.2 -D__PLATFORM_GVSOC__ -D__PLATFORM__=ARCHI_PLATFORM_GVSOC -D__FREERTOS__ -DSCHEDULER_V2 -DSCHEDULER_V3 -D__SEMIHOSTING__ -DPRINTF_SEMIHOST -DPRINTF_DISABLE_SUPPORT_EXPONENTIAL -D__GAP_DRIVER_HOSTFS__=1 -D__GAP_DRIVER_LITTLEFS__=1 -D__GAP_DRIVER_READFS__=1 -D__GAP_DRIVER_VFS__=1 -DCONFIG_VFS_NB=16 -DCHIP_FAMILY=9 -D__GAP9__ -DCHIP_VERSION=2 -D__AUTOTILER_APP__ -I/home/rick/gap_sdk_private/tools/autotiler_v3/Autotiler -I/home/rick/gap_sdk_private/tools/autotiler_v3/Emulation -DF16_DSP_BFLOAT -O3 -DSCHEDULER_V2_THREADS -DTASKS_START_AT_CREATION -DconfigMAX_PRIORITIES=3 -DCONFIG_FREERTOS_USE_TRACE_FACILITIES=0 -DFC_APP_MAIN_STACK_SIZE=2048 -DPI_CL_CC_STACK_SIZE=4096 -DPI_CL_SLAVE_STACK_SIZE=1024 -DCONFIG_FLL_MAXDCO_FREQ=900000000 -DCONFIG_FREQUENCY_PERIPH=370000000 -DCONFIG_FREQUENCY_FC=370000000 -DCONFIG_FREQUENCY_CLUSTER=370000000 -DCONFIG_FREQUENCY_SFU=50000000 -DCONFIG_FREQUENCY_FPGA=50000000 -DCONFIG_FAST_OSC_FREQUENCY=24576063 -DCONFIG_FAST_OSC

C_DEFINES = -DCONFIG_BOARD_GAP9EVK_V1_3 -DCONFIG_BOARD_GAP9MOD_V1_0_B -DCONFIG_DEVICE_TREE -DCONFIG_DRIVER_APS256XXN -DCONFIG_DRIVER_APS256XXN_AS_DEFAULT -DCONFIG_DRIVER_CLUSTERTEAM -DCONFIG_DRIVER_CRC32 -DCONFIG_DRIVER_DEFAULT_FLASH -DCONFIG_DRIVER_DEFAULT_RAM -DCONFIG_DRIVER_FLASH_API -DCONFIG_DRIVER_FLASH_PARTITION_V2=1 -DCONFIG_DRIVER_MRAM -DCONFIG_DRIVER_MX25U51245G -DCONFIG_DRIVER_MX25U51245G_AS_DEFAULT -DCONFIG_DRIVER_POWERSUPPLYGPIO -DCONFIG_DRIVER_POWERSUPPLY_API -DCONFIG_DRIVER_RAM_API -DPI_LOG_DEFAULT_LEVEL=PI_LOG_NONE -DUSE_FLASH_PARTITION_V2=1 -D__BSP_CRC__ -D__BSP_FLASH__ -D__BSP_POWERSUPPLY__ -D__BSP_RAM__

C_INCLUDES = -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/maestro/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i2s/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/efuse/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_core/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fc_event/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pad/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/gpio/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/ffc/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/perf/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/watchdog/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i2c/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i3c/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_datamove/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/spim/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_timeout/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_timestamp/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/dmacpy/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pwm/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/rtc/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/xip/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_hyperbus/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_octospi/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes_dual_core/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_cpi/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_csi2/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_uart/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_fifo/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_sdio/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/quiddikey/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/include -I/home/rick/gap_sdk_private/rtos/pmsis/implem/rtos/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/boards/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/buffer -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/crc32/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mram/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mx25u51245g/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/powersupplygpio/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/aps256xxn/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/include -I/home/rick/gap_sdk_private/rtos/pmsis/bsp/include -I/home/rick/SI_CNN_GAP9/ARMA_50_30/build/devicetree/internal/include -I/home/rick/SI_CNN_GAP9/ARMA_50_30/build/devicetree/include -I/home/rick/SI_CNN_GAP9/ARMA_50_30/build/devicetree/fpv2/include -I/home/rick/gap_sdk_private/rtos/pmsis/include -I/home/rick/gap_sdk_private/libs/baselibs/printf -I/home/rick/gap_sdk_private/rtos/pmsis/tools/assert/include -I/home/rick/gap_sdk_private/rtos/pmsis/tools/allocator/include -I/home/rick/gap_sdk_private/gvsoc/gvsoc/include -I/home/rick/gap_sdk_private/rtos/pmsis/archi/chips/gap9/include -I/home/rick/gap_sdk_private/rtos/pmsis/archi/include -I/home/rick/gap_sdk_private/rtos/pmsis/archi/linker -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/pmsis/include -I/home/rick/gap_sdk_private/rtos/pmsis/api/timer -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/portable/GCC/RI5CY-GAP9 -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/libs/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/include -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/config -I/home/rick/gap_sdk_private/rtos/pmsis/api/include/chips/gap9 -I/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu -I/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/include -I/home/rick/gap_sdk_private/rtos/pmsis/api/include -I/home/rick/gap_sdk_private/rtos/pmsis/api/include/pmsis/rtos

C_FLAGS =  -march=rv32imcxgap9 -mPE=8 -mFC=1 -mint64  -fcommon -fno-jump-tables -fno-tree-loop-distribute-patterns -fno-delete-null-pointer-checks -fomit-frame-pointer -Os -fmessage-length=0 -fno-exceptions -ffunction-sections -fdata-sections -funsigned-char -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable -Wno-unused-but-set-variable -Wno-implicit-fallthrough  -Wno-discarded-qualifiers -std=gnu99 -D__GAP__ -D__riscv__ -D__RISCV_ARCH_GAP__=1 -D__USE_TCDM_MALLOC__=1 -D__FC_MALLOC_NATIVE__=0 -D__L2_MALLOC_NATIVE__=0 -D__PMSIS_L2_MALLOC_NATIVE__=0 -DPMSIS_DRIVERS=1 -DFEATURE_CLUSTER -DGAP_SDK_VERSION=5.20.2 -D__PLATFORM_GVSOC__ -D__PLATFORM__=ARCHI_PLATFORM_GVSOC -D__FREERTOS__ -DSCHEDULER_V2 -DSCHEDULER_V3 -D__SEMIHOSTING__ -DPRINTF_SEMIHOST -DPRINTF_DISABLE_SUPPORT_EXPONENTIAL -D__GAP_DRIVER_HOSTFS__=1 -D__GAP_DRIVER_LITTLEFS__=1 -D__GAP_DRIVER_READFS__=1 -D__GAP_DRIVER_VFS__=1 -DCONFIG_VFS_NB=16 -DCHIP_FAMILY=9 -D__GAP9__ -DCHIP_VERSION=2 -D__AUTOTILER_APP__ -I/home/rick/gap_sdk_private/tools/autotiler_v3/Autotiler -I/home/rick/gap_sdk_private/tools/autotiler_v3/Emulation -DF16_DSP_BFLOAT -O3 -DSCHEDULER_V2_THREADS -DTASKS_START_AT_CREATION -DconfigMAX_PRIORITIES=3 -DCONFIG_FREERTOS_USE_TRACE_FACILITIES=0 -DFC_APP_MAIN_STACK_SIZE=2048 -DPI_CL_CC_STACK_SIZE=4096 -DPI_CL_SLAVE_STACK_SIZE=1024 -DCONFIG_FLL_MAXDCO_FREQ=900000000 -DCONFIG_FREQUENCY_PERIPH=370000000 -DCONFIG_FREQUENCY_FC=370000000 -DCONFIG_FREQUENCY_CLUSTER=370000000 -DCONFIG_FREQUENCY_SFU=50000000 -DCONFIG_FREQUENCY_FPGA=50000000 -DCONFIG_FAST_OSC_FREQUENCY=24576063 -DCONFIG_FAST_OSC

