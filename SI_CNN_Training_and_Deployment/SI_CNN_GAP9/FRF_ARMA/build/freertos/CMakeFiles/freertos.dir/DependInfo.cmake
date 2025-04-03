
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/freertos_task.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/CMakeFiles/freertos.dir/freertos_kernel/freertos_task.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/portable/GCC/RI5CY-GAP9/port_asm.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/CMakeFiles/freertos.dir/freertos_kernel/portable/GCC/RI5CY-GAP9/port_asm.S.obj"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/timer_asm.S" "/home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/CMakeFiles/freertos.dir/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/timer_asm.S.obj"
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
  "/home/rick/gap_sdk_private/rtos/pmsis/api/timer"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/portable/GCC/RI5CY-GAP9"
  "/home/rick/gap_sdk_private/gvsoc/gvsoc/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/libs/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/config"
  "/home/rick/gap_sdk_private/rtos/pmsis/tools/allocator/include"
  "/home/rick/gap_sdk_private/libs/baselibs/printf"
  "/home/rick/gap_sdk_private/rtos/pmsis/archi/chips/gap9/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/archi/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/archi/linker"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/pmsis/include"
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
  "/home/rick/gap_sdk_private/rtos/pmsis/tools/assert/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/include/chips/gap9"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/include"
  "/home/rick/gap_sdk_private/rtos/pmsis/api/include/pmsis/rtos"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/event.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/event.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/event.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/event_groups.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/event_groups.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/event_groups.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/list.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/list.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/list.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/portable/GCC/RI5CY-GAP9/port.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/portable/GCC/RI5CY-GAP9/port.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/portable/GCC/RI5CY-GAP9/port.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/queue.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/queue.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/queue.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/scheduler.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/scheduler.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/scheduler.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/semaphore-v2.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/semaphore-v2.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/semaphore-v2.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/stream_buffer.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/stream_buffer.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/stream_buffer.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/sync_obj-v3.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/sync_obj-v3.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/sync_obj-v3.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/task-v3.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/task-v3.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/task-v3.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/tasks.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/tasks.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/tasks.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/freertos_kernel/timers.c" "freertos/CMakeFiles/freertos.dir/freertos_kernel/timers.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/freertos_kernel/timers.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/timer.c" "freertos/CMakeFiles/freertos.dir/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/timer.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/timer_os/timer.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/config/FreeRTOS_util.c" "freertos/CMakeFiles/freertos.dir/vendors/gwt/gap9/config/FreeRTOS_util.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/vendors/gwt/gap9/config/FreeRTOS_util.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/src/device/freertos_it.c" "freertos/CMakeFiles/freertos.dir/vendors/gwt/gap9/src/device/freertos_it.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/vendors/gwt/gap9/src/device/freertos_it.c.obj.d"
  "/home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/gap9/src/device/gap_it.c" "freertos/CMakeFiles/freertos.dir/vendors/gwt/gap9/src/device/gap_it.c.obj" "gcc" "freertos/CMakeFiles/freertos.dir/vendors/gwt/gap9/src/device/gap_it.c.obj.d"
  )

# Targets to which this target links which contain Fortran sources.
set(CMAKE_Fortran_TARGET_LINKED_INFO_FILES
  )

# Targets to which this target links which contain Fortran sources.
set(CMAKE_Fortran_TARGET_FORWARD_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
