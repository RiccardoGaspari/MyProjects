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

# Utility rule file for installconfig.

# Include any custom commands dependencies for this target.
include CMakeFiles/installconfig.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/installconfig.dir/progress.make

CMakeFiles/installconfig:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying current config to global sdk.config file"
	/home/rick/gap_sdk_private/utils/cmake/kconfigtool.py /home/rick/gap_sdk_private/utils/kconfig/Kconfig /home/rick/SI_CNN_GAP9/AE_CNN/sdk.config /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN/build --cmakeconfig /home/rick/SI_CNN_GAP9/AE_CNN/build/__vars.cmake --appconfigname sdk.config --chip_name gap9 installconfig /home/rick/SI_CNN_GAP9/AE_CNN/build/__vars_timestamp

CMakeFiles/installconfig.dir/codegen:
.PHONY : CMakeFiles/installconfig.dir/codegen

installconfig: CMakeFiles/installconfig
installconfig: CMakeFiles/installconfig.dir/build.make
.PHONY : installconfig

# Rule to build all files generated by this target.
CMakeFiles/installconfig.dir/build: installconfig
.PHONY : CMakeFiles/installconfig.dir/build

CMakeFiles/installconfig.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/installconfig.dir/cmake_clean.cmake
.PHONY : CMakeFiles/installconfig.dir/clean

CMakeFiles/installconfig.dir/depend:
	cd /home/rick/SI_CNN_GAP9/AE_CNN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN/build /home/rick/SI_CNN_GAP9/AE_CNN/build /home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles/installconfig.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/installconfig.dir/depend

