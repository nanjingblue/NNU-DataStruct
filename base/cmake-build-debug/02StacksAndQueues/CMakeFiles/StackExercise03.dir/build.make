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
CMAKE_SOURCE_DIR = C:\workspace\C++\DataStructures\base

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\workspace\C++\DataStructures\base\cmake-build-debug

# Include any dependencies generated for this target.
include 02StacksAndQueues/CMakeFiles/StackExercise03.dir/depend.make
# Include the progress variables for this target.
include 02StacksAndQueues/CMakeFiles/StackExercise03.dir/progress.make

# Include the compile flags for this target's objects.
include 02StacksAndQueues/CMakeFiles/StackExercise03.dir/flags.make

02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.obj: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/flags.make
02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.obj: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/includes_CXX.rsp
02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.obj: ../02StacksAndQueues/StackExercise03.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\workspace\C++\DataStructures\base\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.obj"
	cd /d C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues && C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\StackExercise03.dir\StackExercise03.cpp.obj -c C:\workspace\C++\DataStructures\base\02StacksAndQueues\StackExercise03.cpp

02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StackExercise03.dir/StackExercise03.cpp.i"
	cd /d C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues && C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\workspace\C++\DataStructures\base\02StacksAndQueues\StackExercise03.cpp > CMakeFiles\StackExercise03.dir\StackExercise03.cpp.i

02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StackExercise03.dir/StackExercise03.cpp.s"
	cd /d C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues && C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\workspace\C++\DataStructures\base\02StacksAndQueues\StackExercise03.cpp -o CMakeFiles\StackExercise03.dir\StackExercise03.cpp.s

# Object files for target StackExercise03
StackExercise03_OBJECTS = \
"CMakeFiles/StackExercise03.dir/StackExercise03.cpp.obj"

# External object files for target StackExercise03
StackExercise03_EXTERNAL_OBJECTS =

02StacksAndQueues/StackExercise03.exe: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/StackExercise03.cpp.obj
02StacksAndQueues/StackExercise03.exe: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/build.make
02StacksAndQueues/StackExercise03.exe: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/linklibs.rsp
02StacksAndQueues/StackExercise03.exe: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/objects1.rsp
02StacksAndQueues/StackExercise03.exe: 02StacksAndQueues/CMakeFiles/StackExercise03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\workspace\C++\DataStructures\base\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StackExercise03.exe"
	cd /d C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StackExercise03.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
02StacksAndQueues/CMakeFiles/StackExercise03.dir/build: 02StacksAndQueues/StackExercise03.exe
.PHONY : 02StacksAndQueues/CMakeFiles/StackExercise03.dir/build

02StacksAndQueues/CMakeFiles/StackExercise03.dir/clean:
	cd /d C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues && $(CMAKE_COMMAND) -P CMakeFiles\StackExercise03.dir\cmake_clean.cmake
.PHONY : 02StacksAndQueues/CMakeFiles/StackExercise03.dir/clean

02StacksAndQueues/CMakeFiles/StackExercise03.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\workspace\C++\DataStructures\base C:\workspace\C++\DataStructures\base\02StacksAndQueues C:\workspace\C++\DataStructures\base\cmake-build-debug C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues C:\workspace\C++\DataStructures\base\cmake-build-debug\02StacksAndQueues\CMakeFiles\StackExercise03.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 02StacksAndQueues/CMakeFiles/StackExercise03.dir/depend

