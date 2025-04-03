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

# Utility rule file for vscode.

# Include any custom commands dependencies for this target.
include CMakeFiles/vscode.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vscode.dir/progress.make

CMakeFiles/vscode:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Preparing vscode scripts in .vscode/"
	mkdir -p /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode
	mkdir -p /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/scripts
	cp -rf /home/rick/gap_sdk_private/utils/rules/vscode/settings.json /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode
	cp -rf /home/rick/gap_sdk_private/utils/rules/vscode/launch.json /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode
	cp -rf /home/rick/gap_sdk_private/utils/rules/vscode/tasks.json /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/launch.json @BIN@ /home/rick/SI_CNN_GAP9/FRF_ARMA/build/FRF_multiclass_CNN
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/launch.json @GDB@ `which riscv64-unknown-elf-gdb`
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/tasks.json @GAP_TOOLCHAIN@ /usr/lib/gap_riscv_toolchain
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/tasks.json @GAP_SDK@ /home/rick/gap_sdk_private
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/tasks.json @OCD_install_path@ `which openocd`
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/tasks.json @OPENOCD_CABLE_CFG@ /home/rick/gap_sdk_private/utils/openocd_tools/tcl/gapuino_ftdi.cfg
	/home/rick/gap_sdk_private/utils/rules/vscode/vscode_script_replace.sh /home/rick/SI_CNN_GAP9/FRF_ARMA/.vscode/tasks.json @TARGET_CFG@ /home/rick/gap_sdk_private/utils/openocd_tools/tcl/gap9revb.tcl

CMakeFiles/vscode.dir/codegen:
.PHONY : CMakeFiles/vscode.dir/codegen

vscode: CMakeFiles/vscode
vscode: CMakeFiles/vscode.dir/build.make
.PHONY : vscode

# Rule to build all files generated by this target.
CMakeFiles/vscode.dir/build: vscode
.PHONY : CMakeFiles/vscode.dir/build

CMakeFiles/vscode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vscode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vscode.dir/clean

CMakeFiles/vscode.dir/depend:
	cd /home/rick/SI_CNN_GAP9/FRF_ARMA/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/FRF_ARMA /home/rick/SI_CNN_GAP9/FRF_ARMA /home/rick/SI_CNN_GAP9/FRF_ARMA/build /home/rick/SI_CNN_GAP9/FRF_ARMA/build /home/rick/SI_CNN_GAP9/FRF_ARMA/build/CMakeFiles/vscode.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/vscode.dir/depend

