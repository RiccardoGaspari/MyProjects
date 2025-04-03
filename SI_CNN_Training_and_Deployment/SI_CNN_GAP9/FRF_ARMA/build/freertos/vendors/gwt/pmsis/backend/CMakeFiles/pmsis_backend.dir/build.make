# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/rick/gap_sdk_private/.venv/lib/python3.12/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/rick/gap_sdk_private/.venv/lib/python3.12/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rick/SI_CNN_GAP9/FRF_ARMA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rick/SI_CNN_GAP9/FRF_ARMA/build

# Include any dependencies generated for this target.
include freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/compiler_depend.make

# Include the progress variables for this target.
include freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/progress.make

# Include the compile flags for this target's objects.
include freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/codegen:
.PHONY : freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/codegen

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/main.S.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/main.S.obj: /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/main.S
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/main.S.obj"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/pmsis_backend.dir/src/main.S.obj -c /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/main.S

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/main.S.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing ASM source to CMakeFiles/pmsis_backend.dir/src/main.S.i"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/main.S > CMakeFiles/pmsis_backend.dir/src/main.S.i

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/main.S.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling ASM source to assembly CMakeFiles/pmsis_backend.dir/src/main.S.s"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/main.S -o CMakeFiles/pmsis_backend.dir/src/main.S.s

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/custom_list.c
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj -MF CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj.d -o CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/custom_list.c

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pmsis_backend.dir/src/custom_list.c.i"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/custom_list.c > CMakeFiles/pmsis_backend.dir/src/custom_list.c.i

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pmsis_backend.dir/src/custom_list.c.s"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/custom_list.c -o CMakeFiles/pmsis_backend.dir/src/custom_list.c.s

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_evt.c
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj -MF CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj.d -o CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_evt.c

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pmsis_backend.dir/src/native_evt.c.i"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_evt.c > CMakeFiles/pmsis_backend.dir/src/native_evt.c.i

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pmsis_backend.dir/src/native_evt.c.s"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_evt.c -o CMakeFiles/pmsis_backend.dir/src/native_evt.c.s

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_task.c
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.obj"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.obj -MF CMakeFiles/pmsis_backend.dir/src/native_task.c.obj.d -o CMakeFiles/pmsis_backend.dir/src/native_task.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_task.c

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pmsis_backend.dir/src/native_task.c.i"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_task.c > CMakeFiles/pmsis_backend.dir/src/native_task.c.i

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pmsis_backend.dir/src/native_task.c.s"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/native_task.c -o CMakeFiles/pmsis_backend.dir/src/native_task.c.s

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/sync_obj.c
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj -MF CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj.d -o CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/sync_obj.c

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pmsis_backend.dir/src/sync_obj.c.i"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/sync_obj.c > CMakeFiles/pmsis_backend.dir/src/sync_obj.c.i

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pmsis_backend.dir/src/sync_obj.c.s"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/sync_obj.c -o CMakeFiles/pmsis_backend.dir/src/sync_obj.c.s

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/flags.make
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/os.c
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.obj: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.obj"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.obj -MF CMakeFiles/pmsis_backend.dir/src/os.c.obj.d -o CMakeFiles/pmsis_backend.dir/src/os.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/os.c

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pmsis_backend.dir/src/os.c.i"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/os.c > CMakeFiles/pmsis_backend.dir/src/os.c.i

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pmsis_backend.dir/src/os.c.s"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend/src/os.c -o CMakeFiles/pmsis_backend.dir/src/os.c.s

# Object files for target pmsis_backend
pmsis_backend_OBJECTS = \
"CMakeFiles/pmsis_backend.dir/src/main.S.obj" \
"CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj" \
"CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj" \
"CMakeFiles/pmsis_backend.dir/src/native_task.c.obj" \
"CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj" \
"CMakeFiles/pmsis_backend.dir/src/os.c.obj"

# External object files for target pmsis_backend
pmsis_backend_EXTERNAL_OBJECTS =

freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/main.S.obj
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/custom_list.c.obj
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_evt.c.obj
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/native_task.c.obj
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/sync_obj.c.obj
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/src/os.c.obj
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/build.make
freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a: freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C static library libpmsis_backend.a"
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && $(CMAKE_COMMAND) -P CMakeFiles/pmsis_backend.dir/cmake_clean_target.cmake
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pmsis_backend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/build: freertos/vendors/gwt/pmsis/backend/libpmsis_backend.a
.PHONY : freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/build

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/clean:
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend && $(CMAKE_COMMAND) -P CMakeFiles/pmsis_backend.dir/cmake_clean.cmake
.PHONY : freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/clean

freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/depend:
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/FRF_ARMA /home/rick/gap_sdk_private/rtos/pmsis/os/freeRTOS/vendors/gwt/pmsis/backend /home/rick/SI_CNN_GAP9/FRF_ARMA/build /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend /home/rick/SI_CNN_GAP9/FRF_ARMA/build/freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : freertos/vendors/gwt/pmsis/backend/CMakeFiles/pmsis_backend.dir/depend

