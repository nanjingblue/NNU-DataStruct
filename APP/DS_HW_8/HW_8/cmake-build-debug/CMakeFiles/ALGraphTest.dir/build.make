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
include CMakeFiles/ALGraphTest.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ALGraphTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ALGraphTest.dir/flags.make

CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.obj: CMakeFiles/ALGraphTest.dir/flags.make
CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.obj: CMakeFiles/ALGraphTest.dir/includes_CXX.rsp
CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.obj: ../ALGraphTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.obj"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ALGraphTest.dir\ALGraphTest.cpp.obj -c C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\ALGraphTest.cpp

CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.i"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\ALGraphTest.cpp > CMakeFiles\ALGraphTest.dir\ALGraphTest.cpp.i

CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.s"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\ALGraphTest.cpp -o CMakeFiles\ALGraphTest.dir\ALGraphTest.cpp.s

# Object files for target ALGraphTest
ALGraphTest_OBJECTS = \
"CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.obj"

# External object files for target ALGraphTest
ALGraphTest_EXTERNAL_OBJECTS =

ALGraphTest.exe: CMakeFiles/ALGraphTest.dir/ALGraphTest.cpp.obj
ALGraphTest.exe: CMakeFiles/ALGraphTest.dir/build.make
ALGraphTest.exe: CMakeFiles/ALGraphTest.dir/linklibs.rsp
ALGraphTest.exe: CMakeFiles/ALGraphTest.dir/objects1.rsp
ALGraphTest.exe: CMakeFiles/ALGraphTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ALGraphTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ALGraphTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ALGraphTest.dir/build: ALGraphTest.exe
.PHONY : CMakeFiles/ALGraphTest.dir/build

CMakeFiles/ALGraphTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ALGraphTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ALGraphTest.dir/clean

CMakeFiles/ALGraphTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8 C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8 C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug C:\workspace\C++\DataStructures\APP\DS_HW_8\HW_8\cmake-build-debug\CMakeFiles\ALGraphTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ALGraphTest.dir/depend
