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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/code/main

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/code/main/build

# Include any dependencies generated for this target.
include coroutine/CMakeFiles/coroutine.dir/depend.make

# Include the progress variables for this target.
include coroutine/CMakeFiles/coroutine.dir/progress.make

# Include the compile flags for this target's objects.
include coroutine/CMakeFiles/coroutine.dir/flags.make

coroutine/CMakeFiles/coroutine.dir/coroutine.cpp.o: coroutine/CMakeFiles/coroutine.dir/flags.make
coroutine/CMakeFiles/coroutine.dir/coroutine.cpp.o: ../coroutine/coroutine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object coroutine/CMakeFiles/coroutine.dir/coroutine.cpp.o"
	cd /data/code/main/build/coroutine && /usr/bin/x86_64-redhat-linux-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coroutine.dir/coroutine.cpp.o -c /data/code/main/coroutine/coroutine.cpp

coroutine/CMakeFiles/coroutine.dir/coroutine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coroutine.dir/coroutine.cpp.i"
	cd /data/code/main/build/coroutine && /usr/bin/x86_64-redhat-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/coroutine/coroutine.cpp > CMakeFiles/coroutine.dir/coroutine.cpp.i

coroutine/CMakeFiles/coroutine.dir/coroutine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coroutine.dir/coroutine.cpp.s"
	cd /data/code/main/build/coroutine && /usr/bin/x86_64-redhat-linux-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/coroutine/coroutine.cpp -o CMakeFiles/coroutine.dir/coroutine.cpp.s

# Object files for target coroutine
coroutine_OBJECTS = \
"CMakeFiles/coroutine.dir/coroutine.cpp.o"

# External object files for target coroutine
coroutine_EXTERNAL_OBJECTS =

coroutine/libcoroutine.a: coroutine/CMakeFiles/coroutine.dir/coroutine.cpp.o
coroutine/libcoroutine.a: coroutine/CMakeFiles/coroutine.dir/build.make
coroutine/libcoroutine.a: coroutine/CMakeFiles/coroutine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/code/main/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcoroutine.a"
	cd /data/code/main/build/coroutine && $(CMAKE_COMMAND) -P CMakeFiles/coroutine.dir/cmake_clean_target.cmake
	cd /data/code/main/build/coroutine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coroutine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
coroutine/CMakeFiles/coroutine.dir/build: coroutine/libcoroutine.a

.PHONY : coroutine/CMakeFiles/coroutine.dir/build

coroutine/CMakeFiles/coroutine.dir/clean:
	cd /data/code/main/build/coroutine && $(CMAKE_COMMAND) -P CMakeFiles/coroutine.dir/cmake_clean.cmake
.PHONY : coroutine/CMakeFiles/coroutine.dir/clean

coroutine/CMakeFiles/coroutine.dir/depend:
	cd /data/code/main/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/code/main /data/code/main/coroutine /data/code/main/build /data/code/main/build/coroutine /data/code/main/build/coroutine/CMakeFiles/coroutine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : coroutine/CMakeFiles/coroutine.dir/depend

