# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/APC_randomness.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/APC_randomness.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/APC_randomness.dir/flags.make

CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.o: CMakeFiles/APC_randomness.dir/flags.make
CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.o: ../examples/std_rand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.o -c "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/examples/std_rand.cpp"

CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/examples/std_rand.cpp" > CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.i

CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/examples/std_rand.cpp" -o CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.s

CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.o: CMakeFiles/APC_randomness.dir/flags.make
CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.o: ../examples/cpp11rand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.o"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.o -c "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/examples/cpp11rand.cpp"

CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.i"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/examples/cpp11rand.cpp" > CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.i

CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.s"
	/opt/homebrew/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/examples/cpp11rand.cpp" -o CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.s

# Object files for target APC_randomness
APC_randomness_OBJECTS = \
"CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.o" \
"CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.o"

# External object files for target APC_randomness
APC_randomness_EXTERNAL_OBJECTS =

APC_randomness: CMakeFiles/APC_randomness.dir/examples/std_rand.cpp.o
APC_randomness: CMakeFiles/APC_randomness.dir/examples/cpp11rand.cpp.o
APC_randomness: CMakeFiles/APC_randomness.dir/build.make
APC_randomness: CMakeFiles/APC_randomness.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable APC_randomness"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/APC_randomness.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/APC_randomness.dir/build: APC_randomness
.PHONY : CMakeFiles/APC_randomness.dir/build

CMakeFiles/APC_randomness.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/APC_randomness.dir/cmake_clean.cmake
.PHONY : CMakeFiles/APC_randomness.dir/clean

CMakeFiles/APC_randomness.dir/depend:
	cd "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness" "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness" "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug" "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug" "/Users/camiel/Documents/school/TI2/Advanced Programming Concepts/APC-randomness/cmake-build-debug/CMakeFiles/APC_randomness.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/APC_randomness.dir/depend

