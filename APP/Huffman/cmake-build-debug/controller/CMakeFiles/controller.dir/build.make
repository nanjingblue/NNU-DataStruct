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
CMAKE_SOURCE_DIR = C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug

# Include any dependencies generated for this target.
include controller/CMakeFiles/controller.dir/depend.make
# Include the progress variables for this target.
include controller/CMakeFiles/controller.dir/progress.make

# Include the compile flags for this target's objects.
include controller/CMakeFiles/controller.dir/flags.make

controller/CMakeFiles/controller.dir/TreeCreator.cpp.obj: controller/CMakeFiles/controller.dir/flags.make
controller/CMakeFiles/controller.dir/TreeCreator.cpp.obj: ../controller/TreeCreator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object controller/CMakeFiles/controller.dir/TreeCreator.cpp.obj"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller && C:\env\mingw64\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\controller.dir\TreeCreator.cpp.obj -c C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\controller\TreeCreator.cpp

controller/CMakeFiles/controller.dir/TreeCreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/controller.dir/TreeCreator.cpp.i"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller && C:\env\mingw64\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\controller\TreeCreator.cpp > CMakeFiles\controller.dir\TreeCreator.cpp.i

controller/CMakeFiles/controller.dir/TreeCreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/controller.dir/TreeCreator.cpp.s"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller && C:\env\mingw64\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\controller\TreeCreator.cpp -o CMakeFiles\controller.dir\TreeCreator.cpp.s

# Object files for target controller
controller_OBJECTS = \
"CMakeFiles/controller.dir/TreeCreator.cpp.obj"

# External object files for target controller
controller_EXTERNAL_OBJECTS =

controller/libcontroller.a: controller/CMakeFiles/controller.dir/TreeCreator.cpp.obj
controller/libcontroller.a: controller/CMakeFiles/controller.dir/build.make
controller/libcontroller.a: controller/CMakeFiles/controller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcontroller.a"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller && $(CMAKE_COMMAND) -P CMakeFiles\controller.dir\cmake_clean_target.cmake
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\controller.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
controller/CMakeFiles/controller.dir/build: controller/libcontroller.a
.PHONY : controller/CMakeFiles/controller.dir/build

controller/CMakeFiles/controller.dir/clean:
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller && $(CMAKE_COMMAND) -P CMakeFiles\controller.dir\cmake_clean.cmake
.PHONY : controller/CMakeFiles/controller.dir/clean

controller/CMakeFiles/controller.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\controller C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\cmake-build-debug\controller\CMakeFiles\controller.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : controller/CMakeFiles/controller.dir/depend

