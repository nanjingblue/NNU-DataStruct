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
CMAKE_SOURCE_DIR = C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MGraphTest.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MGraphTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MGraphTest.dir/flags.make

CMakeFiles/MGraphTest.dir/MGraphTest.cpp.obj: CMakeFiles/MGraphTest.dir/flags.make
CMakeFiles/MGraphTest.dir/MGraphTest.cpp.obj: CMakeFiles/MGraphTest.dir/includes_CXX.rsp
CMakeFiles/MGraphTest.dir/MGraphTest.cpp.obj: ../MGraphTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MGraphTest.dir/MGraphTest.cpp.obj"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MGraphTest.dir\MGraphTest.cpp.obj -c C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\MGraphTest.cpp

CMakeFiles/MGraphTest.dir/MGraphTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MGraphTest.dir/MGraphTest.cpp.i"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\MGraphTest.cpp > CMakeFiles\MGraphTest.dir\MGraphTest.cpp.i

CMakeFiles/MGraphTest.dir/MGraphTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MGraphTest.dir/MGraphTest.cpp.s"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\MGraphTest.cpp -o CMakeFiles\MGraphTest.dir\MGraphTest.cpp.s

# Object files for target MGraphTest
MGraphTest_OBJECTS = \
"CMakeFiles/MGraphTest.dir/MGraphTest.cpp.obj"

# External object files for target MGraphTest
MGraphTest_EXTERNAL_OBJECTS =

MGraphTest.exe: CMakeFiles/MGraphTest.dir/MGraphTest.cpp.obj
MGraphTest.exe: CMakeFiles/MGraphTest.dir/build.make
MGraphTest.exe: CMakeFiles/MGraphTest.dir/linklibs.rsp
MGraphTest.exe: CMakeFiles/MGraphTest.dir/objects1.rsp
MGraphTest.exe: CMakeFiles/MGraphTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MGraphTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MGraphTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MGraphTest.dir/build: MGraphTest.exe
.PHONY : CMakeFiles/MGraphTest.dir/build

CMakeFiles/MGraphTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MGraphTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MGraphTest.dir/clean

CMakeFiles/MGraphTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8 C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8 C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug\CMakeFiles\MGraphTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MGraphTest.dir/depend

