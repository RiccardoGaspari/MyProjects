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

# Utility rule file for run.

# Include any custom commands dependencies for this target.
include CMakeFiles/run.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run.dir/progress.make

CMakeFiles/run:
	/home/rick/gap_sdk_private/utils/gapy_v2/bin/gapy --target=gap9.evk --target-dir=/home/rick/gap_sdk_private/install/workstation/generators --model-dir=/home/rick/gap_sdk_private/install/workstation/models --platform=gvsoc --work-dir=/home/rick/SI_CNN_GAP9/AE_FC/build --target-property=boot.flash_device=mram --target-property=boot.mode=flash --multi-flash-content=/home/rick/gap_sdk_private/utils/layouts/default_layout_multi_readfs_lfs.json --flash-property=/home/rick/SI_CNN_GAP9/AE_FC/build/FCAutoEncoder@mram:app:binary run --binary=/home/rick/SI_CNN_GAP9/AE_FC/build/FCAutoEncoder --flash-property=/home/rick/SI_CNN_GAP9/AE_FC/build/BUILD_MODEL/FCAutoEncoder_L3_Flash_Const.dat@flash:readfs_flash:files --py-stack --flash-property=/home/rick/gap_sdk_private/install/target/bin/fsbl@mram:fsbl:binary --flash-property=/home/rick/gap_sdk_private/install/target/bin/ssbl@mram:ssbl:binary

CMakeFiles/run.dir/codegen:
.PHONY : CMakeFiles/run.dir/codegen

run: CMakeFiles/run
run: CMakeFiles/run.dir/build.make
.PHONY : run

# Rule to build all files generated by this target.
CMakeFiles/run.dir/build: run
.PHONY : CMakeFiles/run.dir/build

CMakeFiles/run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run.dir/clean

CMakeFiles/run.dir/depend:
	cd /home/rick/SI_CNN_GAP9/AE_FC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/AE_FC /home/rick/SI_CNN_GAP9/AE_FC /home/rick/SI_CNN_GAP9/AE_FC/build /home/rick/SI_CNN_GAP9/AE_FC/build /home/rick/SI_CNN_GAP9/AE_FC/build/CMakeFiles/run.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run.dir/depend

