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

# Utility rule file for dump_dis.

# Include any custom commands dependencies for this target.
include CMakeFiles/dump_dis.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dump_dis.dir/progress.make

CMakeFiles/dump_dis: ARMA_30_10_Bin_All
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/ARMA_30_10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Invoking: OBJDUMP, dump disassembly in /home/rick/SI_CNN_GAP9/ARMA_30_10/build/ARMA_30_10_Bin_All.s"
	/usr/lib/gap_riscv_toolchain/bin/riscv32-unknown-elf-objdump -d -h -S -t -w --show-raw-insn /home/rick/SI_CNN_GAP9/ARMA_30_10/build/ARMA_30_10_Bin_All > /home/rick/SI_CNN_GAP9/ARMA_30_10/build/ARMA_30_10_Bin_All.s

CMakeFiles/dump_dis.dir/codegen:
.PHONY : CMakeFiles/dump_dis.dir/codegen

dump_dis: CMakeFiles/dump_dis
dump_dis: CMakeFiles/dump_dis.dir/build.make
.PHONY : dump_dis

# Rule to build all files generated by this target.
CMakeFiles/dump_dis.dir/build: dump_dis
.PHONY : CMakeFiles/dump_dis.dir/build

CMakeFiles/dump_dis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dump_dis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dump_dis.dir/clean

CMakeFiles/dump_dis.dir/depend:
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/ARMA_30_10 /home/rick/SI_CNN_GAP9/ARMA_30_10 /home/rick/SI_CNN_GAP9/ARMA_30_10/build /home/rick/SI_CNN_GAP9/ARMA_30_10/build /home/rick/SI_CNN_GAP9/ARMA_30_10/build/CMakeFiles/dump_dis.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dump_dis.dir/depend

