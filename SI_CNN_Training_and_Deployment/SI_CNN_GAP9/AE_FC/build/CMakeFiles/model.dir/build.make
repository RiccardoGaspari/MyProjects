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

# Utility rule file for model.

# Include any custom commands dependencies for this target.
include CMakeFiles/model.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/model.dir/progress.make

CMakeFiles/model.dir/codegen:
.PHONY : CMakeFiles/model.dir/codegen

model: CMakeFiles/model.dir/build.make
.PHONY : model

# Rule to build all files generated by this target.
CMakeFiles/model.dir/build: model
.PHONY : CMakeFiles/model.dir/build

CMakeFiles/model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/model.dir/clean

CMakeFiles/model.dir/depend:
	cd /home/rick/SI_CNN_GAP9/AE_FC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/AE_FC /home/rick/SI_CNN_GAP9/AE_FC /home/rick/SI_CNN_GAP9/AE_FC/build /home/rick/SI_CNN_GAP9/AE_FC/build /home/rick/SI_CNN_GAP9/AE_FC/build/CMakeFiles/model.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/model.dir/depend

