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
CMAKE_SOURCE_DIR = /home/rick/SI_CNN_GAP9/ARMA_50_30

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rick/SI_CNN_GAP9/ARMA_50_30/build

# Include any dependencies generated for this target.
include pmsis/printf/CMakeFiles/pmsis_printf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include pmsis/printf/CMakeFiles/pmsis_printf.dir/compiler_depend.make

# Include the progress variables for this target.
include pmsis/printf/CMakeFiles/pmsis_printf.dir/progress.make

# Include the compile flags for this target's objects.
include pmsis/printf/CMakeFiles/pmsis_printf.dir/flags.make

pmsis/printf/CMakeFiles/pmsis_printf.dir/codegen:
.PHONY : pmsis/printf/CMakeFiles/pmsis_printf.dir/codegen

pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.obj: pmsis/printf/CMakeFiles/pmsis_printf.dir/flags.make
pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.obj: /home/rick/gap_sdk_private/libs/baselibs/printf/printf.c
pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.obj: pmsis/printf/CMakeFiles/pmsis_printf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rick/SI_CNN_GAP9/ARMA_50_30/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.obj"
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.obj -MF CMakeFiles/pmsis_printf.dir/printf.c.obj.d -o CMakeFiles/pmsis_printf.dir/printf.c.obj -c /home/rick/gap_sdk_private/libs/baselibs/printf/printf.c

pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pmsis_printf.dir/printf.c.i"
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rick/gap_sdk_private/libs/baselibs/printf/printf.c > CMakeFiles/pmsis_printf.dir/printf.c.i

pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pmsis_printf.dir/printf.c.s"
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf && /usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rick/gap_sdk_private/libs/baselibs/printf/printf.c -o CMakeFiles/pmsis_printf.dir/printf.c.s

# Object files for target pmsis_printf
pmsis_printf_OBJECTS = \
"CMakeFiles/pmsis_printf.dir/printf.c.obj"

# External object files for target pmsis_printf
pmsis_printf_EXTERNAL_OBJECTS =

pmsis/printf/libpmsis_printf.a: pmsis/printf/CMakeFiles/pmsis_printf.dir/printf.c.obj
pmsis/printf/libpmsis_printf.a: pmsis/printf/CMakeFiles/pmsis_printf.dir/build.make
pmsis/printf/libpmsis_printf.a: pmsis/printf/CMakeFiles/pmsis_printf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rick/SI_CNN_GAP9/ARMA_50_30/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libpmsis_printf.a"
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf && $(CMAKE_COMMAND) -P CMakeFiles/pmsis_printf.dir/cmake_clean_target.cmake
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pmsis_printf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pmsis/printf/CMakeFiles/pmsis_printf.dir/build: pmsis/printf/libpmsis_printf.a
.PHONY : pmsis/printf/CMakeFiles/pmsis_printf.dir/build

pmsis/printf/CMakeFiles/pmsis_printf.dir/clean:
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf && $(CMAKE_COMMAND) -P CMakeFiles/pmsis_printf.dir/cmake_clean.cmake
.PHONY : pmsis/printf/CMakeFiles/pmsis_printf.dir/clean

pmsis/printf/CMakeFiles/pmsis_printf.dir/depend:
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/ARMA_50_30 /home/rick/gap_sdk_private/libs/baselibs/printf /home/rick/SI_CNN_GAP9/ARMA_50_30/build /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf /home/rick/SI_CNN_GAP9/ARMA_50_30/build/pmsis/printf/CMakeFiles/pmsis_printf.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : pmsis/printf/CMakeFiles/pmsis_printf.dir/depend

