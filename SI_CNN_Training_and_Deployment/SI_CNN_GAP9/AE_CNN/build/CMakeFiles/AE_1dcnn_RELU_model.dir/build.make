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

# Utility rule file for AE_1dcnn_RELU_model.

# Include any custom commands dependencies for this target.
include CMakeFiles/AE_1dcnn_RELU_model.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AE_1dcnn_RELU_model.dir/progress.make

CMakeFiles/AE_1dcnn_RELU_model: BUILD_MODEL/AE_1dcnn_RELUKernels.c
CMakeFiles/AE_1dcnn_RELU_model: BUILD_MODEL/AE_1dcnn_RELUKernels.h

BUILD_MODEL/AE_1dcnn_RELUKernels.c: BUILD_MODEL/GenAE_1dcnn_RELU
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running GenAE_1dcnn_RELU to create Kernel C files : AE_1dcnn_RELUKernels.c  with args -c/home/rick/SI_CNN_GAP9/AE_CNN/build/tensors;--L1=115712;--L2=1300000;--L3=8000000;--L2STATIC=-1;--L3STATIC=-1;--log_level=0;-o/home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL"
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "RUNNING AUTOTILER MODEL - START"
	/home/rick/gap_sdk_private/.venv/lib/python3.12/site-packages/cmake/data/bin/cmake -E make_directory /home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL
	/home/rick/gap_sdk_private/.venv/lib/python3.12/site-packages/cmake/data/bin/cmake -E make_directory /home/rick/SI_CNN_GAP9/AE_CNN/build/tensors
	if [ -n true ]; then touch /home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL/AE_1dcnn_RELU_L3_Flash_Const.dat ; fi
	if [ -n  ]; then touch _not_used ; fi
	BUILD_MODEL/GenAE_1dcnn_RELU -c/home/rick/SI_CNN_GAP9/AE_CNN/build/tensors --L1=115712 --L2=1300000 --L3=8000000 --L2STATIC=-1 --L3STATIC=-1 --log_level=0 -o/home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL

BUILD_MODEL/AE_1dcnn_RELUKernels.h: BUILD_MODEL/AE_1dcnn_RELUKernels.c
	@$(CMAKE_COMMAND) -E touch_nocreate BUILD_MODEL/AE_1dcnn_RELUKernels.h

BUILD_MODEL/GenAE_1dcnn_RELU: model_dir/model.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/CNN_Generator_Util.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/CNN_Copy_Generators.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/SSD_Generators.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Generators/ResizeGenerator.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Generators/ISP_Generators.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Generators/DSP_Generatorsv2.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Generators/DSP_Generators.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/CNN_Generators.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_SQ8/CNN_Generators_SQ8.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_SQ8/RNN_Generators_SQ8.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16/CNN_Generators_NE16.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16/RNN_Generators_NE16.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16/RNN_Generators_NE16_v2.c
BUILD_MODEL/GenAE_1dcnn_RELU: /home/rick/gap_sdk_private/tools/autotiler_v3/Autotiler/LibTile.a
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Compiling Autotiler Model : /home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL/GenAE_1dcnn_RELU (depends on: /home/rick/SI_CNN_GAP9/AE_CNN/build/model_dir/model.c /home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL)"
	/home/rick/gap_sdk_private/.venv/lib/python3.12/site-packages/cmake/data/bin/cmake -E make_directory /home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL
	gcc -g -o /home/rick/SI_CNN_GAP9/AE_CNN/build/BUILD_MODEL/GenAE_1dcnn_RELU -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators -I/home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Generators -I/home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Generators -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp16 -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp16/CNN_Libraries_fp16x -I/home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Generators -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_SQ8 -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16 -I/home/rick/gap_sdk_private/libs/include -I/home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Libraries -I/home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Libraries -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp32 -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp16 -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_fp16/CNN_Libraries_fp16x -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_SQ8 -I/home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Libraries_NE16 -I/home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Librariesv2 -I/home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Librariesv2/FastMathFunctions -I/home/rick/gap_sdk_private/tools/autotiler_v3/Autotiler -I/home/rick/gap_sdk_private/tools/autotiler_v3/Emulation /home/rick/SI_CNN_GAP9/AE_CNN/build/model_dir/model.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/CNN_Generator_Util.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/CNN_Copy_Generators.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/SSD_Generators.c /home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Generators/ResizeGenerator.c /home/rick/gap_sdk_private/tools/autotiler_v3/ISP_Generators/ISP_Generators.c /home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Generators/DSP_Generatorsv2.c /home/rick/gap_sdk_private/tools/autotiler_v3/DSP_Generators/DSP_Generators.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators/CNN_Generators.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_SQ8/CNN_Generators_SQ8.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_SQ8/RNN_Generators_SQ8.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16/CNN_Generators_NE16.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16/RNN_Generators_NE16.c /home/rick/gap_sdk_private/tools/autotiler_v3/CNN_Generators_NE16/RNN_Generators_NE16_v2.c /home/rick/gap_sdk_private/tools/autotiler_v3/Autotiler/LibTile.a -lm

model_dir/model.c: /home/rick/SI_CNN_GAP9/AE_CNN/gen_AE_1dcnn_RELU_at_model.py
model_dir/model.c: /home/rick/SI_CNN_GAP9/AE_CNN/AE_1dcnn_RELU.onnx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generate the autotiler model, tensors and expressions code: /home/rick/SI_CNN_GAP9/AE_CNN/build/model_dir/model.c /home/rick/SI_CNN_GAP9/AE_CNN/build/model_dir/Expression_Kernels.c /home/rick/SI_CNN_GAP9/AE_CNN/build/tensors"
	python3 /home/rick/SI_CNN_GAP9/AE_CNN/gen_AE_1dcnn_RELU_at_model.py --at_model_path=/home/rick/SI_CNN_GAP9/AE_CNN/build/model_dir/model.c --tensors_dir=/home/rick/SI_CNN_GAP9/AE_CNN/build/tensors --trained_model=/home/rick/SI_CNN_GAP9/AE_CNN/AE_1dcnn_RELU.onnx --flash_type=AT_MEM_L3_DEFAULTFLASH --ram_type=AT_MEM_L3_DEFAULTRAM

model_dir/Expression_Kernels.c: model_dir/model.c
	@$(CMAKE_COMMAND) -E touch_nocreate model_dir/Expression_Kernels.c

tensors: model_dir/model.c
	@$(CMAKE_COMMAND) -E touch_nocreate tensors

CMakeFiles/AE_1dcnn_RELU_model.dir/codegen:
.PHONY : CMakeFiles/AE_1dcnn_RELU_model.dir/codegen

AE_1dcnn_RELU_model: BUILD_MODEL/AE_1dcnn_RELUKernels.c
AE_1dcnn_RELU_model: BUILD_MODEL/AE_1dcnn_RELUKernels.h
AE_1dcnn_RELU_model: BUILD_MODEL/GenAE_1dcnn_RELU
AE_1dcnn_RELU_model: CMakeFiles/AE_1dcnn_RELU_model
AE_1dcnn_RELU_model: model_dir/Expression_Kernels.c
AE_1dcnn_RELU_model: model_dir/model.c
AE_1dcnn_RELU_model: tensors
AE_1dcnn_RELU_model: CMakeFiles/AE_1dcnn_RELU_model.dir/build.make
.PHONY : AE_1dcnn_RELU_model

# Rule to build all files generated by this target.
CMakeFiles/AE_1dcnn_RELU_model.dir/build: AE_1dcnn_RELU_model
.PHONY : CMakeFiles/AE_1dcnn_RELU_model.dir/build

CMakeFiles/AE_1dcnn_RELU_model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AE_1dcnn_RELU_model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AE_1dcnn_RELU_model.dir/clean

CMakeFiles/AE_1dcnn_RELU_model.dir/depend:
	cd /home/rick/SI_CNN_GAP9/AE_CNN/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN /home/rick/SI_CNN_GAP9/AE_CNN/build /home/rick/SI_CNN_GAP9/AE_CNN/build /home/rick/SI_CNN_GAP9/AE_CNN/build/CMakeFiles/AE_1dcnn_RELU_model.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/AE_1dcnn_RELU_model.dir/depend

