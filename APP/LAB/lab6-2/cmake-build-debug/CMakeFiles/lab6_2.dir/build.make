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
CMAKE_SOURCE_DIR = C:\workspace\C++\DataStructures\APP\LAB\lab6-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\workspace\C++\DataStructures\APP\LAB\lab6-2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab6_2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab6_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6_2.dir/flags.make

CMakeFiles/lab6_2.dir/main.cpp.obj: CMakeFiles/lab6_2.dir/flags.make
CMakeFiles/lab6_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\workspace\C++\DataStructures\APP\LAB\lab6-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6_2.dir/main.cpp.obj"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab6_2.dir\main.cpp.obj -c C:\workspace\C++\DataStructures\APP\LAB\lab6-2\main.cpp

CMakeFiles/lab6_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6_2.dir/main.cpp.i"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\workspace\C++\DataStructures\APP\LAB\lab6-2\main.cpp > CMakeFiles\lab6_2.dir\main.cpp.i

CMakeFiles/lab6_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6_2.dir/main.cpp.s"
	C:\env\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\workspace\C++\DataStructures\APP\LAB\lab6-2\main.cpp -o CMakeFiles\lab6_2.dir\main.cpp.s

# Object files for target lab6_2
lab6_2_OBJECTS = \
"CMakeFiles/lab6_2.dir/main.cpp.obj"

# External object files for target lab6_2
lab6_2_EXTERNAL_OBJECTS =

lab6_2.exe: CMakeFiles/lab6_2.dir/main.cpp.obj
lab6_2.exe: CMakeFiles/lab6_2.dir/build.make
lab6_2.exe: CMakeFiles/lab6_2.dir/linklibs.rsp
lab6_2.exe: CMakeFiles/lab6_2.dir/objects1.rsp
lab6_2.exe: CMakeFiles/lab6_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\workspace\C++\DataStructures\APP\LAB\lab6-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab6_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab6_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6_2.dir/build: lab6_2.exe
.PHONY : CMakeFiles/lab6_2.dir/build

CMakeFiles/lab6_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab6_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab6_2.dir/clean

CMakeFiles/lab6_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\workspace\C++\DataStructures\APP\LAB\lab6-2 C:\workspace\C++\DataStructures\APP\LAB\lab6-2 C:\workspace\C++\DataStructures\APP\LAB\lab6-2\cmake-build-debug C:\workspace\C++\DataStructures\APP\LAB\lab6-2\cmake-build-debug C:\workspace\C++\DataStructures\APP\LAB\lab6-2\cmake-build-debug\CMakeFiles\lab6_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab6_2.dir/depend

