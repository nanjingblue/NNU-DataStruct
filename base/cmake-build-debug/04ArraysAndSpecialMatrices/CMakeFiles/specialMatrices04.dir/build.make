# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cherry\Documents\workspace\C++\DataStructures\base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug

# Include any dependencies generated for this target.
include 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/depend.make
# Include the progress variables for this target.
include 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/progress.make

# Include the compile flags for this target's objects.
include 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/flags.make

04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.obj: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/flags.make
04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.obj: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/includes_CXX.rsp
04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.obj: ../04ArraysAndSpecialMatrices/specialMatrices04.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.obj"
	cd /d C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices && C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\specialMatrices04.dir\specialMatrices04.cpp.obj -c C:\Users\cherry\Documents\workspace\C++\DataStructures\base\04ArraysAndSpecialMatrices\specialMatrices04.cpp

04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.i"
	cd /d C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices && C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cherry\Documents\workspace\C++\DataStructures\base\04ArraysAndSpecialMatrices\specialMatrices04.cpp > CMakeFiles\specialMatrices04.dir\specialMatrices04.cpp.i

04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.s"
	cd /d C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices && C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cherry\Documents\workspace\C++\DataStructures\base\04ArraysAndSpecialMatrices\specialMatrices04.cpp -o CMakeFiles\specialMatrices04.dir\specialMatrices04.cpp.s

# Object files for target specialMatrices04
specialMatrices04_OBJECTS = \
"CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.obj"

# External object files for target specialMatrices04
specialMatrices04_EXTERNAL_OBJECTS =

04ArraysAndSpecialMatrices/specialMatrices04.exe: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/specialMatrices04.cpp.obj
04ArraysAndSpecialMatrices/specialMatrices04.exe: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/build.make
04ArraysAndSpecialMatrices/specialMatrices04.exe: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/linklibs.rsp
04ArraysAndSpecialMatrices/specialMatrices04.exe: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/objects1.rsp
04ArraysAndSpecialMatrices/specialMatrices04.exe: 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable specialMatrices04.exe"
	cd /d C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\specialMatrices04.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/build: 04ArraysAndSpecialMatrices/specialMatrices04.exe
.PHONY : 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/build

04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/clean:
	cd /d C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices && $(CMAKE_COMMAND) -P CMakeFiles\specialMatrices04.dir\cmake_clean.cmake
.PHONY : 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/clean

04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cherry\Documents\workspace\C++\DataStructures\base C:\Users\cherry\Documents\workspace\C++\DataStructures\base\04ArraysAndSpecialMatrices C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices C:\Users\cherry\Documents\workspace\C++\DataStructures\base\cmake-build-debug\04ArraysAndSpecialMatrices\CMakeFiles\specialMatrices04.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 04ArraysAndSpecialMatrices/CMakeFiles/specialMatrices04.dir/depend

