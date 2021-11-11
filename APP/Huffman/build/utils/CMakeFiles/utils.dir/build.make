# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = C:\env\cmake-3.21.2\bin\cmake.exe

# The command to remove a file.
RM = C:\env\cmake-3.21.2\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build

# Include any dependencies generated for this target.
include utils/CMakeFiles/utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include utils/CMakeFiles/utils.dir/compiler_depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/utils.dir/flags.make

utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj: ../utils/TreeCreatorUtils.cpp
utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils && C:\env\mingw64\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj -MF CMakeFiles\utils.dir\TreeCreatorUtils.cpp.obj.d -o CMakeFiles\utils.dir\TreeCreatorUtils.cpp.obj -c C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\utils\TreeCreatorUtils.cpp

utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/TreeCreatorUtils.cpp.i"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils && C:\env\mingw64\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\utils\TreeCreatorUtils.cpp > CMakeFiles\utils.dir\TreeCreatorUtils.cpp.i

utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/TreeCreatorUtils.cpp.s"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils && C:\env\mingw64\bin\g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\utils\TreeCreatorUtils.cpp -o CMakeFiles\utils.dir\TreeCreatorUtils.cpp.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

utils/libutils.a: utils/CMakeFiles/utils.dir/TreeCreatorUtils.cpp.obj
utils/libutils.a: utils/CMakeFiles/utils.dir/build.make
utils/libutils.a: utils/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libutils.a"
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils && $(CMAKE_COMMAND) -P CMakeFiles\utils.dir\cmake_clean_target.cmake
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\utils.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/utils.dir/build: utils/libutils.a
.PHONY : utils/CMakeFiles/utils.dir/build

utils/CMakeFiles/utils.dir/clean:
	cd /d C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils && $(CMAKE_COMMAND) -P CMakeFiles\utils.dir\cmake_clean.cmake
.PHONY : utils/CMakeFiles/utils.dir/clean

utils/CMakeFiles/utils.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\utils C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils C:\Users\cherry\Desktop\workspace\C++\DataStructures\APP\Huffman\build\utils\CMakeFiles\utils.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/utils.dir/depend
