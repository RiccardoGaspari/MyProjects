
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/driver/cluster-cc.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/cluster/driver/cluster-cc.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/driver/cluster-pe-team.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/cluster/driver/cluster-pe-team.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/driver/cluster-pe-workgroup.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/cluster/driver/cluster-pe-workgroup.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/gap_iet.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/gap_iet.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/gpio/driver/gpio_asm.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/gpio/driver/gpio_asm.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_octospi/driver/octospi_asm.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_octospi/driver/octospi_asm.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/asm_util.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/utils/asm_util.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/startup_gap.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/pmsis/CMakeFiles/pmsis.dir/implem/utils/startup_gap.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "CONFIG_BOARD_GAP9EVK_V1_3"
  "CONFIG_BOARD_GAP9MOD_V1_0_B"
  "CONFIG_DEVICE_TREE"
  "CONFIG_DRIVER_APS256XXN"
  "CONFIG_DRIVER_APS256XXN_AS_DEFAULT"
  "CONFIG_DRIVER_CLUSTERTEAM"
  "CONFIG_DRIVER_CRC32"
  "CONFIG_DRIVER_DEFAULT_FLASH"
  "CONFIG_DRIVER_DEFAULT_RAM"
  "CONFIG_DRIVER_FLASH_API"
  "CONFIG_DRIVER_FLASH_PARTITION_V2=1"
  "CONFIG_DRIVER_MRAM"
  "CONFIG_DRIVER_MX25U51245G"
  "CONFIG_DRIVER_MX25U51245G_AS_DEFAULT"
  "CONFIG_DRIVER_POWERSUPPLYGPIO"
  "CONFIG_DRIVER_POWERSUPPLY_API"
  "CONFIG_DRIVER_RAM_API"
  "PI_LOG_DEFAULT_LEVEL=PI_LOG_NONE"
  "USE_FLASH_PARTITION_V2=1"
  "__BSP_CRC__"
  "__BSP_FLASH__"
  "__BSP_POWERSUPPLY__"
  "__BSP_RAM__"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/maestro/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i2s/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/efuse/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_core/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fc_event/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pad/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/gpio/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/ffc/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/perf/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/watchdog/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i2c/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/i3c/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_datamove/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/spim/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_timeout/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_timestamp/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/dmacpy/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pwm/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/rtc/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/xip/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_hyperbus/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_octospi/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes_dual_core/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_cpi/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_csi2/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_uart/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_fifo/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_sdio/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/quiddikey/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/rtos/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/boards/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/buffer"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/crc32/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/api/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mram/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mx25u51245g/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/api/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/powersupplygpio/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/api/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/aps256xxn/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/include"
  "devicetree/internal/include"
  "devicetree/include"
  "devicetree/fpv2/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/include"
  "/home/rick/gap_sdk_private/libs/baselibs/printf"
  "/home/rick/gap_sdk_private/rtos/pmsis/tools/assert/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/tools/allocator/include"
  "/home/rick/gap_sdk_private/gvsoc/gvsoc/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/archi/chips/gap9/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/archi/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/archi/linker"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/pmsis/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/timer"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/portable/GCC/RI5CY-GAP9"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/libs/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/config"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/include/chips/gap9"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/include/pmsis/rtos"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/devicetree/fpv2/devicetree_fpv2.c" "pmsis/CMakeFiles/pmsis.dir/__/devicetree/fpv2/devicetree_fpv2.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/__/devicetree/fpv2/devicetree_fpv2.c.obj.d"
  "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/devicetree/internal/devicetree_internal.c" "pmsis/CMakeFiles/pmsis.dir/__/devicetree/internal/devicetree_internal.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/__/devicetree/internal/devicetree_internal.c.obj.d"
  "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/devicetree/src/dt.c" "pmsis/CMakeFiles/pmsis.dir/__/devicetree/src/dt.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/__/devicetree/src/dt.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/boards/src/bsp_gap9evk_v1_3.c" "pmsis/CMakeFiles/pmsis.dir/bsp/boards/src/bsp_gap9evk_v1_3.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/boards/src/bsp_gap9evk_v1_3.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/boards/src/bsp_gap9mod_v1_0_b.c" "pmsis/CMakeFiles/pmsis.dir/bsp/boards/src/bsp_gap9mod_v1_0_b.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/boards/src/bsp_gap9mod_v1_0_b.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/bsp/bsp.c" "pmsis/CMakeFiles/pmsis.dir/bsp/bsp/bsp.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/bsp/bsp.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/crc/crc32/crc32.c" "pmsis/CMakeFiles/pmsis.dir/bsp/crc/crc32/crc32.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/crc/crc32/crc32.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/api/flash.c" "pmsis/CMakeFiles/pmsis.dir/bsp/flash/api/flash.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/flash/api/flash.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mram/mram-v2.c" "pmsis/CMakeFiles/pmsis.dir/bsp/flash/mram/mram-v2.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/flash/mram/mram-v2.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/flash/mx25u51245g/mx25u51245g.c" "pmsis/CMakeFiles/pmsis.dir/bsp/flash/mx25u51245g/mx25u51245g.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/flash/mx25u51245g/mx25u51245g.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/fs.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/fs.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/fs.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/host_fs/host_fs.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/host_fs/host_fs.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/host_fs/host_fs.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/lfs/lfs.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/lfs/lfs.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/lfs/lfs.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/lfs/lfs_util.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/lfs/lfs_util.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/lfs/lfs_util.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/lfs/pi_lfs.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/lfs/pi_lfs.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/lfs/pi_lfs.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/read_fs/read_fs.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/read_fs/read_fs.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/read_fs/read_fs.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/fs/vfs.c" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/vfs.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/fs/vfs.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/partition/flash_partition_v2.c" "pmsis/CMakeFiles/pmsis.dir/bsp/partition/flash_partition_v2.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/partition/flash_partition_v2.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/partition/secret_storage.c" "pmsis/CMakeFiles/pmsis.dir/bsp/partition/secret_storage.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/partition/secret_storage.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/api/powersupply.c" "pmsis/CMakeFiles/pmsis.dir/bsp/powersupply/api/powersupply.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/powersupply/api/powersupply.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/powersupply/powersupplygpio/powersupplygpio.c" "pmsis/CMakeFiles/pmsis.dir/bsp/powersupply/powersupplygpio/powersupplygpio.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/powersupply/powersupplygpio/powersupplygpio.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/api/alloc_extern.c" "pmsis/CMakeFiles/pmsis.dir/bsp/ram/api/alloc_extern.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/ram/api/alloc_extern.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/api/ram.c" "pmsis/CMakeFiles/pmsis.dir/bsp/ram/api/ram.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/ram/api/ram.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/bsp/ram/aps256xxn/aps256xxn.c" "pmsis/CMakeFiles/pmsis.dir/bsp/ram/aps256xxn/aps256xxn.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/bsp/ram/aps256xxn/aps256xxn.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/cluster/driver/cluster.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/cluster/driver/cluster.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/cluster/driver/cluster.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/efuse/driver/efuse.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/efuse/driver/efuse.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/efuse/driver/efuse.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fc_event/driver/fc_event.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/fc_event/driver/fc_event.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/fc_event/driver/fc_event.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/gpio/driver/gpio.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/gpio/driver/gpio.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/gpio/driver/gpio.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/maestro/driver/maestro.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/maestro/driver/maestro.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/maestro/driver/maestro.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/maestro/driver/maestro_irq.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/maestro/driver/maestro_irq.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/maestro/driver/maestro_irq.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/pad/driver/pad.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/pad/driver/pad.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/pad/driver/pad.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/quiddikey/driver/quiddikey_internal.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/quiddikey/driver/quiddikey_internal.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/quiddikey/driver/quiddikey_internal.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer/driver/pi_timer.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/timer/driver/pi_timer.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/timer/driver/pi_timer.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes/driver/aes.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_aes/driver/aes.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_aes/driver/aes.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes/driver/aes_internal.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_aes/driver/aes_internal.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_aes/driver/aes_internal.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_aes_dual_core/driver/aes_dual_core_internal.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_aes_dual_core/driver/aes_dual_core_internal.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_aes_dual_core/driver/aes_dual_core_internal.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_core/driver/udma_core.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_core/driver/udma_core.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_core/driver/udma_core.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/udma_octospi/driver/octospi.c" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_octospi/driver/octospi.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/chips/gap9/udma_octospi/driver/octospi.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/rtos/malloc/pi_cl_malloc.c" "pmsis/CMakeFiles/pmsis.dir/implem/rtos/malloc/pi_cl_malloc.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/rtos/malloc/pi_cl_malloc.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/rtos/os/system_gap.c" "pmsis/CMakeFiles/pmsis.dir/implem/rtos/os/system_gap.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/rtos/os/system_gap.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/ctors_dtors.c" "pmsis/CMakeFiles/pmsis.dir/implem/utils/ctors_dtors.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/utils/ctors_dtors.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/device.c" "pmsis/CMakeFiles/pmsis.dir/implem/utils/device.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/utils/device.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/gap_io.c" "pmsis/CMakeFiles/pmsis.dir/implem/utils/gap_io.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/utils/gap_io.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/host_sync_access.c" "pmsis/CMakeFiles/pmsis.dir/implem/utils/host_sync_access.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/utils/host_sync_access.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/pi_log.c" "pmsis/CMakeFiles/pmsis.dir/implem/utils/pi_log.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/utils/pi_log.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/utils/time.c" "pmsis/CMakeFiles/pmsis.dir/implem/utils/time.c.obj" "gcc" "pmsis/CMakeFiles/pmsis.dir/implem/utils/time.c.obj.d"
  )

# Targets to which this target links which contain Fortran sources.
set(CMAKE_Fortran_TARGET_LINKED_INFO_FILES
  )

# Targets to which this target links which contain Fortran sources.
set(CMAKE_Fortran_TARGET_FORWARD_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
