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

# Utility rule file for install_bin.

# Include any custom commands dependencies for this target.
include CMakeFiles/install_bin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/install_bin.dir/progress.make

CMakeFiles/install_bin:
	cp /home/rick/SI_CNN_GAP9/ARMA_30_10/build/ARMA_30_10_Bin_All /home/rick/gap_sdk_private/install/target/bin

CMakeFiles/install_bin.dir/codegen:
.PHONY : CMakeFiles/install_bin.dir/codegen

install_bin: CMakeFiles/install_bin
install_bin: CMakeFiles/install_bin.dir/build.make
.PHONY : install_bin

# Rule to build all files generated by this target.
CMakeFiles/install_bin.dir/build: install_bin
.PHONY : CMakeFiles/install_bin.dir/build

CMakeFiles/install_bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/install_bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/install_bin.dir/clean

CMakeFiles/install_bin.dir/depend:
	cd /home/rick/SI_CNN_GAP9/ARMA_30_10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/ARMA_30_10 /home/rick/SI_CNN_GAP9/ARMA_30_10 /home/rick/SI_CNN_GAP9/ARMA_30_10/build /home/rick/SI_CNN_GAP9/ARMA_30_10/build /home/rick/SI_CNN_GAP9/ARMA_30_10/build/CMakeFiles/install_bin.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/install_bin.dir/depend

