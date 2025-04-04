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
CMAKE_SOURCE_DIR = /home/rick/SI_CNN_GAP9/ARMA_30_10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rick/SI_CNN_GAP9/ARMA_30_10/build

# Include any dependencies generated for this target.
include pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/progress.make

# Include the compile flags for this target's objects.
include pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/flags.make

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/codegen:
.PHONY : pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/codegen

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/flags.make
pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/fll/fll.c
pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/ARMA_30_10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj -MF CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj.d -o CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/fll/fll.c

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fll_pmu_lib.dir/fll/fll.c.i"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/fll/fll.c > CMakeFiles/fll_pmu_lib.dir/fll/fll.c.i

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fll_pmu_lib.dir/fll/fll.c.s"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/fll/fll.c -o CMakeFiles/fll_pmu_lib.dir/fll/fll.c.s

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/flags.make
pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj: /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/pmu/maestro_voltage.c
pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/ARMA_30_10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj -MF CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj.d -o CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj -c /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/pmu/maestro_voltage.c

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.i"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/pmu/maestro_voltage.c > CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.i

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.s"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu/pmu/maestro_voltage.c -o CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.s

# Object files for target fll_pmu_lib
fll_pmu_lib_OBJECTS = \
"CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj" \
"CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj"

# External object files for target fll_pmu_lib
fll_pmu_lib_EXTERNAL_OBJECTS =

pmsis/fll_pmu/libfll_pmu_lib.a: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/fll/fll.c.obj
pmsis/fll_pmu/libfll_pmu_lib.a: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/pmu/maestro_voltage.c.obj
pmsis/fll_pmu/libfll_pmu_lib.a: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/build.make
pmsis/fll_pmu/libfll_pmu_lib.a: pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rick/SI_CNN_GAP9/ARMA_30_10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libfll_pmu_lib.a"
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && $(CMAKE_COMMAND) -P CMakeFiles/fll_pmu_lib.dir/cmake_clean_target.cmake
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fll_pmu_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/build: pmsis/fll_pmu/libfll_pmu_lib.a
.PHONY : pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/build

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/clean:
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu && $(CMAKE_COMMAND) -P CMakeFiles/fll_pmu_lib.dir/cmake_clean.cmake
.PHONY : pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/clean

pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/depend:
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/ARMA_30_10 /home/rick/gap_sdk_private/rtos/pmsis/implem/chips/gap9/fll_pmu /home/rick/SI_CNN_GAP9/ARMA_30_10/build /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu /home/rick/SI_CNN_GAP9/ARMA_30_10/build/pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : pmsis/fll_pmu/CMakeFiles/fll_pmu_lib.dir/depend

