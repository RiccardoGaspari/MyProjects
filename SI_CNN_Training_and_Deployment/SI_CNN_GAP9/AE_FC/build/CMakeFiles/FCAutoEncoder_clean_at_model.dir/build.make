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
CMAKE_SOURCE_DIR = /home/rick/SI_CNN_GAP9/AE_FC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rick/SI_CNN_GAP9/AE_FC/build

# Utility rule file for FCAutoEncoder_clean_at_model.

# Include any custom commands dependencies for this target.
include CMakeFiles/FCAutoEncoder_clean_at_model.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FCAutoEncoder_clean_at_model.dir/progress.make

CMakeFiles/FCAutoEncoder_clean_at_model:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/AE_FC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "clean_at_model: removing /home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/GenFCAutoEncoder /home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/FCAutoEncoderKernels.c /home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/FCAutoEncoderKernels.h"
	rm -rf /home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/GenFCAutoEncoder /home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/FCAutoEncoderKernels.c /home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/FCAutoEncoderKernels.h

CMakeFiles/FCAutoEncoder_clean_at_model.dir/codegen:
.PHONY : CMakeFiles/FCAutoEncoder_clean_at_model.dir/codegen

FCAutoEncoder_clean_at_model: CMakeFiles/FCAutoEncoder_clean_at_model
FCAutoEncoder_clean_at_model: CMakeFiles/FCAutoEncoder_clean_at_model.dir/build.make
.PHONY : FCAutoEncoder_clean_at_model

# Rule to build all files generated by this target.
CMakeFiles/FCAutoEncoder_clean_at_model.dir/build: FCAutoEncoder_clean_at_model
.PHONY : CMakeFiles/FCAutoEncoder_clean_at_model.dir/build

CMakeFiles/FCAutoEncoder_clean_at_model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FCAutoEncoder_clean_at_model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FCAutoEncoder_clean_at_model.dir/clean

CMakeFiles/FCAutoEncoder_clean_at_model.dir/depend:
	cd /home/rick/SI_CNN_GAP9/AE_FC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/AE_FC /home/rick/SI_CNN_GAP9/AE_FC /home/rick/SI_CNN_GAP9/AE_FC/build /home/rick/SI_CNN_GAP9/AE_FC/build /home/rick/SI_CNN_GAP9/AE_FC/build/CMakeFiles/FCAutoEncoder_clean_at_model.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FCAutoEncoder_clean_at_model.dir/depend

