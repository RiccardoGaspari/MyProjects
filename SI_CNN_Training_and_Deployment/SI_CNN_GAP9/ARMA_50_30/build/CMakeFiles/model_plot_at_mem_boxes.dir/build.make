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

# Utility rule file for model_plot_at_mem_boxes.

# Include any custom commands dependencies for this target.
include CMakeFiles/model_plot_at_mem_boxes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/model_plot_at_mem_boxes.dir/progress.make

CMakeFiles/model_plot_at_mem_boxes.dir/codegen:
.PHONY : CMakeFiles/model_plot_at_mem_boxes.dir/codegen

model_plot_at_mem_boxes: CMakeFiles/model_plot_at_mem_boxes.dir/build.make
.PHONY : model_plot_at_mem_boxes

# Rule to build all files generated by this target.
CMakeFiles/model_plot_at_mem_boxes.dir/build: model_plot_at_mem_boxes
.PHONY : CMakeFiles/model_plot_at_mem_boxes.dir/build

CMakeFiles/model_plot_at_mem_boxes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/model_plot_at_mem_boxes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/model_plot_at_mem_boxes.dir/clean

CMakeFiles/model_plot_at_mem_boxes.dir/depend:
	cd /home/rick/SI_CNN_GAP9/ARMA_50_30/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/ARMA_50_30 /home/rick/SI_CNN_GAP9/ARMA_50_30 /home/rick/SI_CNN_GAP9/ARMA_50_30/build /home/rick/SI_CNN_GAP9/ARMA_50_30/build /home/rick/SI_CNN_GAP9/ARMA_50_30/build/CMakeFiles/model_plot_at_mem_boxes.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/model_plot_at_mem_boxes.dir/depend

