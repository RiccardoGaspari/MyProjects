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

# Utility rule file for FRF_multiclass_CNN_plot_at_mem_boxes.

# Include any custom commands dependencies for this target.
include CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/progress.make

CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Plot memory boxes information from Autotiler run (NOTE: the name of the ATBoxes file might differ from default: /home/rick/SI_CNN_GAP9/FRF_ARMA/build/BUILD_MODEL/FRF_multiclass_CNNCNN_AtBoxesDump.txt)"
	echo RUNNING\ AUTOTILER\ MODEL\ -\ START > /home/rick/SI_CNN_GAP9/FRF_ARMA/build/BUILD_MODEL/FRF_multiclass_CNNAtLog.txt
	BUILD_MODEL/GenFRF_multiclass_CNN -c/home/rick/SI_CNN_GAP9/FRF_ARMA/build/tensors --L1=115712 --L2=1300000 --L3=8000000 --L2STATIC=-1 --L3STATIC=-1 --log_level=0 -o/home/rick/SI_CNN_GAP9/FRF_ARMA/build/BUILD_MODEL >> /home/rick/SI_CNN_GAP9/FRF_ARMA/build/BUILD_MODEL/FRF_multiclass_CNNAtLog.txt
	python /home/rick/gap_sdk_private/tools/nntool/nntool_python_utils/plot_at_mem_boxes.py /home/rick/SI_CNN_GAP9/FRF_ARMA/build/BUILD_MODEL/FRF_multiclass_CNNCNN_AtBoxesDump.txt /home/rick/SI_CNN_GAP9/FRF_ARMA/build/BUILD_MODEL/FRF_multiclass_CNNAtLog.txt

CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/codegen:
.PHONY : CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/codegen

FRF_multiclass_CNN_plot_at_mem_boxes: CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes
FRF_multiclass_CNN_plot_at_mem_boxes: CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/build.make
.PHONY : FRF_multiclass_CNN_plot_at_mem_boxes

# Rule to build all files generated by this target.
CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/build: FRF_multiclass_CNN_plot_at_mem_boxes
.PHONY : CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/build

CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/clean

CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/depend:
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/FRF_ARMA /home/rick/SI_CNN_GAP9/FRF_ARMA /home/rick/SI_CNN_GAP9/FRF_ARMA/build /home/rick/SI_CNN_GAP9/FRF_ARMA/build /home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FRF_multiclass_CNN_plot_at_mem_boxes.dir/depend

