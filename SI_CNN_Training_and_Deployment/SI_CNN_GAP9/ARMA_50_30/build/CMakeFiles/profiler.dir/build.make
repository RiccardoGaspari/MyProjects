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

# Utility rule file for profiler.

# Include any custom commands dependencies for this target.
include CMakeFiles/profiler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/profiler.dir/progress.make

CMakeFiles/profiler:
	/home/rick/gap_sdk_private/utils/gapy_v2/bin/gapy --target=gap9.evk --target-dir=/home/rick/gap_sdk_private/install/workstation/generators --model-dir=/home/rick/gap_sdk_private/install/workstation/models --platform=gvsoc --work-dir=/home/rick/SI_CNN_GAP9/ARMA_50_30/build --binary=/home/rick/SI_CNN_GAP9/ARMA_50_30/build/ARMA_50_30_Bin_All --target-property=boot.flash_device=mram --target-property=boot.mode=flash --multi-flash-content=/home/rick/gap_sdk_private/utils/layouts/default_layout_multi_readfs_lfs.json --flash-property=/home/rick/SI_CNN_GAP9/ARMA_50_30/build/ARMA_50_30_Bin_All@mram:app:binary --config-opt="gvsoc/debug-mode=true" --config-opt="gvsoc/events/gen_gtkw=false" prepare && profiler gvsoc_config.json --signal-tree-file=/home/rick/gap_sdk_private/tools/profiler_v2/gui/images/signalstree_gap9.json

CMakeFiles/profiler.dir/codegen:
.PHONY : CMakeFiles/profiler.dir/codegen

profiler: CMakeFiles/profiler
profiler: CMakeFiles/profiler.dir/build.make
.PHONY : profiler

# Rule to build all files generated by this target.
CMakeFiles/profiler.dir/build: profiler
.PHONY : CMakeFiles/profiler.dir/build

CMakeFiles/profiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/profiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/profiler.dir/clean

CMakeFiles/profiler.dir/depend:
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/ARMA_50_30 /home/rick/SI_CNN_GAP9/ARMA_50_30 /home/rick/SI_CNN_GAP9/ARMA_50_30/build /home/rick/SI_CNN_GAP9/ARMA_50_30/build /home/rick/SI_CNN_GAP9/ARMA_50_30/build/CMakeFiles/profiler.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/profiler.dir/depend

