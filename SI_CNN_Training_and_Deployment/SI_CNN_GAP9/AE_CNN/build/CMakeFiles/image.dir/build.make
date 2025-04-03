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
CMAKE_SOURCE_DIR = /home/rick/SI_CNN_GAP9/AE_CNN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rick/SI_CNN_GAP9/AE_CNN/build

# Utility rule file for image.

# Include any custom commands dependencies for this target.
include CMakeFiles/image.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image.dir/progress.make

CMakeFiles/image: AE_1dcnn_RELU
	/home/rick/gap_sdk_private/utils/gapy_v2/bin/gapy --target=gap9.evk --target-dir=/home/rick/gap_sdk_private/install/workstation/generators --model-dir=/home/rick/gap_sdk_private/install/workstation/models --platform=gvsoc --work-dir=/home/rick/SI_CNN_GAP9/AE_CNN/build --target-property=boot.flash_device=mram --target-property=boot.mode=flash --multi-flash-content=/home/rick/gap_sdk_private/utils/layouts/default_layout_multi_readfs_lfs.json --flash-property=/home/rick/SI_CNN_GAP9/AE_CNN/build/AE_1dcnn_RELU@mram:app:binary image --binary=/home/rick/SI_CNN_GAP9/AE_CNN/build/AE_1dcnn_RELU --flash-property=/home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL/AE_1dcnn_RELU_L3_Flash_Const.dat@flash:readfs_flash:files --py-stack --flash-property=/home/rick/gap_sdk_private/install/target/bin/fsbl@mram:fsbl:binary --flash-property=/home/rick/gap_sdk_private/install/target/bin/ssbl@mram:ssbl:binary

CMakeFiles/image.dir/codegen:
.PHONY : CMakeFiles/image.dir/codegen

image: CMakeFiles/image
image: CMakeFiles/image.dir/build.make
.PHONY : image

# Rule to build all files generated by this target.
CMakeFiles/image.dir/build: image
.PHONY : CMakeFiles/image.dir/build

CMakeFiles/image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image.dir/clean

CMakeFiles/image.dir/depend:
	cd /home/rick/SI_CNN_GAP9/AE_CNN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN/build /home/rick/SI_CNN_GAP9/AE_CNN/build /home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles/image.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/image.dir/depend

