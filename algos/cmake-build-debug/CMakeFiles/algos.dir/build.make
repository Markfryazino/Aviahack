# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/Prog/Cpp/Aviahack/algos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/algos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algos.dir/flags.make

CMakeFiles/algos.dir/main.cpp.o: CMakeFiles/algos.dir/flags.make
CMakeFiles/algos.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algos.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algos.dir/main.cpp.o -c /home/ivan/Prog/Cpp/Aviahack/algos/main.cpp

CMakeFiles/algos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algos.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Prog/Cpp/Aviahack/algos/main.cpp > CMakeFiles/algos.dir/main.cpp.i

CMakeFiles/algos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algos.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Prog/Cpp/Aviahack/algos/main.cpp -o CMakeFiles/algos.dir/main.cpp.s

CMakeFiles/algos.dir/greedy.cpp.o: CMakeFiles/algos.dir/flags.make
CMakeFiles/algos.dir/greedy.cpp.o: ../greedy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/algos.dir/greedy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algos.dir/greedy.cpp.o -c /home/ivan/Prog/Cpp/Aviahack/algos/greedy.cpp

CMakeFiles/algos.dir/greedy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algos.dir/greedy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Prog/Cpp/Aviahack/algos/greedy.cpp > CMakeFiles/algos.dir/greedy.cpp.i

CMakeFiles/algos.dir/greedy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algos.dir/greedy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Prog/Cpp/Aviahack/algos/greedy.cpp -o CMakeFiles/algos.dir/greedy.cpp.s

# Object files for target algos
algos_OBJECTS = \
"CMakeFiles/algos.dir/main.cpp.o" \
"CMakeFiles/algos.dir/greedy.cpp.o"

# External object files for target algos
algos_EXTERNAL_OBJECTS =

algos: CMakeFiles/algos.dir/main.cpp.o
algos: CMakeFiles/algos.dir/greedy.cpp.o
algos: CMakeFiles/algos.dir/build.make
algos: CMakeFiles/algos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable algos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algos.dir/build: algos

.PHONY : CMakeFiles/algos.dir/build

CMakeFiles/algos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algos.dir/clean

CMakeFiles/algos.dir/depend:
	cd /home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/Prog/Cpp/Aviahack/algos /home/ivan/Prog/Cpp/Aviahack/algos /home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug /home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug /home/ivan/Prog/Cpp/Aviahack/algos/cmake-build-debug/CMakeFiles/algos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algos.dir/depend

