# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/data_sapiens/Anaconda/lib/python3.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/data_sapiens/Anaconda/lib/python3.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/data_sapiens/programs/projects/aviahack/algos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/data_sapiens/programs/projects/aviahack/algos/build

# Include any dependencies generated for this target.
include CMakeFiles/algos.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algos.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algos.dir/flags.make

CMakeFiles/algos.dir/main.cpp.o: CMakeFiles/algos.dir/flags.make
CMakeFiles/algos.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/data_sapiens/programs/projects/aviahack/algos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algos.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algos.dir/main.cpp.o -c /home/data_sapiens/programs/projects/aviahack/algos/main.cpp

CMakeFiles/algos.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algos.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/data_sapiens/programs/projects/aviahack/algos/main.cpp > CMakeFiles/algos.dir/main.cpp.i

CMakeFiles/algos.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algos.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/data_sapiens/programs/projects/aviahack/algos/main.cpp -o CMakeFiles/algos.dir/main.cpp.s

CMakeFiles/algos.dir/greedy.cpp.o: CMakeFiles/algos.dir/flags.make
CMakeFiles/algos.dir/greedy.cpp.o: ../greedy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/data_sapiens/programs/projects/aviahack/algos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/algos.dir/greedy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algos.dir/greedy.cpp.o -c /home/data_sapiens/programs/projects/aviahack/algos/greedy.cpp

CMakeFiles/algos.dir/greedy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algos.dir/greedy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/data_sapiens/programs/projects/aviahack/algos/greedy.cpp > CMakeFiles/algos.dir/greedy.cpp.i

CMakeFiles/algos.dir/greedy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algos.dir/greedy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/data_sapiens/programs/projects/aviahack/algos/greedy.cpp -o CMakeFiles/algos.dir/greedy.cpp.s

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
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/data_sapiens/programs/projects/aviahack/algos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable algos"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algos.dir/build: algos

.PHONY : CMakeFiles/algos.dir/build

CMakeFiles/algos.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algos.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algos.dir/clean

CMakeFiles/algos.dir/depend:
	cd /home/data_sapiens/programs/projects/aviahack/algos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/data_sapiens/programs/projects/aviahack/algos /home/data_sapiens/programs/projects/aviahack/algos /home/data_sapiens/programs/projects/aviahack/algos/build /home/data_sapiens/programs/projects/aviahack/algos/build /home/data_sapiens/programs/projects/aviahack/algos/build/CMakeFiles/algos.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algos.dir/depend
