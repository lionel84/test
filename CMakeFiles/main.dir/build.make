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
CMAKE_BINARY_DIR = /data/code/main

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/base.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/base.cpp.o: base.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/base.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/base.cpp.o -c /data/code/main/base.cpp

CMakeFiles/main.dir/base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/base.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/base.cpp > CMakeFiles/main.dir/base.cpp.i

CMakeFiles/main.dir/base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/base.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/base.cpp -o CMakeFiles/main.dir/base.cpp.s

CMakeFiles/main.dir/cache.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/cache.cpp.o: cache.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/cache.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/cache.cpp.o -c /data/code/main/cache.cpp

CMakeFiles/main.dir/cache.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/cache.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/cache.cpp > CMakeFiles/main.dir/cache.cpp.i

CMakeFiles/main.dir/cache.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/cache.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/cache.cpp -o CMakeFiles/main.dir/cache.cpp.s

CMakeFiles/main.dir/coroutine_test.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/coroutine_test.cpp.o: coroutine_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/coroutine_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/coroutine_test.cpp.o -c /data/code/main/coroutine_test.cpp

CMakeFiles/main.dir/coroutine_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/coroutine_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/coroutine_test.cpp > CMakeFiles/main.dir/coroutine_test.cpp.i

CMakeFiles/main.dir/coroutine_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/coroutine_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/coroutine_test.cpp -o CMakeFiles/main.dir/coroutine_test.cpp.s

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /data/code/main/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/rank_rbtree.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/rank_rbtree.cpp.o: rank_rbtree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/rank_rbtree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/rank_rbtree.cpp.o -c /data/code/main/rank_rbtree.cpp

CMakeFiles/main.dir/rank_rbtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/rank_rbtree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/rank_rbtree.cpp > CMakeFiles/main.dir/rank_rbtree.cpp.i

CMakeFiles/main.dir/rank_rbtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/rank_rbtree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/rank_rbtree.cpp -o CMakeFiles/main.dir/rank_rbtree.cpp.s

CMakeFiles/main.dir/rank_skip_list.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/rank_skip_list.cpp.o: rank_skip_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/rank_skip_list.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/rank_skip_list.cpp.o -c /data/code/main/rank_skip_list.cpp

CMakeFiles/main.dir/rank_skip_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/rank_skip_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/rank_skip_list.cpp > CMakeFiles/main.dir/rank_skip_list.cpp.i

CMakeFiles/main.dir/rank_skip_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/rank_skip_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/rank_skip_list.cpp -o CMakeFiles/main.dir/rank_skip_list.cpp.s

CMakeFiles/main.dir/rank_test.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/rank_test.cpp.o: rank_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/rank_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/rank_test.cpp.o -c /data/code/main/rank_test.cpp

CMakeFiles/main.dir/rank_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/rank_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/rank_test.cpp > CMakeFiles/main.dir/rank_test.cpp.i

CMakeFiles/main.dir/rank_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/rank_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/rank_test.cpp -o CMakeFiles/main.dir/rank_test.cpp.s

CMakeFiles/main.dir/redis_test.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/redis_test.cpp.o: redis_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/redis_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/redis_test.cpp.o -c /data/code/main/redis_test.cpp

CMakeFiles/main.dir/redis_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/redis_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/redis_test.cpp > CMakeFiles/main.dir/redis_test.cpp.i

CMakeFiles/main.dir/redis_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/redis_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/redis_test.cpp -o CMakeFiles/main.dir/redis_test.cpp.s

CMakeFiles/main.dir/socket_test.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/socket_test.cpp.o: socket_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/socket_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/socket_test.cpp.o -c /data/code/main/socket_test.cpp

CMakeFiles/main.dir/socket_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/socket_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/socket_test.cpp > CMakeFiles/main.dir/socket_test.cpp.i

CMakeFiles/main.dir/socket_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/socket_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/socket_test.cpp -o CMakeFiles/main.dir/socket_test.cpp.s

CMakeFiles/main.dir/test_aes_cbc.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_aes_cbc.cpp.o: test_aes_cbc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/main.dir/test_aes_cbc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_aes_cbc.cpp.o -c /data/code/main/test_aes_cbc.cpp

CMakeFiles/main.dir/test_aes_cbc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_aes_cbc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_aes_cbc.cpp > CMakeFiles/main.dir/test_aes_cbc.cpp.i

CMakeFiles/main.dir/test_aes_cbc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_aes_cbc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_aes_cbc.cpp -o CMakeFiles/main.dir/test_aes_cbc.cpp.s

CMakeFiles/main.dir/test_auto_ptr.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_auto_ptr.cpp.o: test_auto_ptr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/main.dir/test_auto_ptr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_auto_ptr.cpp.o -c /data/code/main/test_auto_ptr.cpp

CMakeFiles/main.dir/test_auto_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_auto_ptr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_auto_ptr.cpp > CMakeFiles/main.dir/test_auto_ptr.cpp.i

CMakeFiles/main.dir/test_auto_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_auto_ptr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_auto_ptr.cpp -o CMakeFiles/main.dir/test_auto_ptr.cpp.s

CMakeFiles/main.dir/test_bt.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_bt.cpp.o: test_bt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/main.dir/test_bt.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_bt.cpp.o -c /data/code/main/test_bt.cpp

CMakeFiles/main.dir/test_bt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_bt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_bt.cpp > CMakeFiles/main.dir/test_bt.cpp.i

CMakeFiles/main.dir/test_bt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_bt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_bt.cpp -o CMakeFiles/main.dir/test_bt.cpp.s

CMakeFiles/main.dir/test_comp.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_comp.cpp.o: test_comp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/main.dir/test_comp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_comp.cpp.o -c /data/code/main/test_comp.cpp

CMakeFiles/main.dir/test_comp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_comp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_comp.cpp > CMakeFiles/main.dir/test_comp.cpp.i

CMakeFiles/main.dir/test_comp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_comp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_comp.cpp -o CMakeFiles/main.dir/test_comp.cpp.s

CMakeFiles/main.dir/test_function.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_function.cpp.o: test_function.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/main.dir/test_function.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_function.cpp.o -c /data/code/main/test_function.cpp

CMakeFiles/main.dir/test_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_function.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_function.cpp > CMakeFiles/main.dir/test_function.cpp.i

CMakeFiles/main.dir/test_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_function.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_function.cpp -o CMakeFiles/main.dir/test_function.cpp.s

CMakeFiles/main.dir/test_json_pack.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_json_pack.cpp.o: test_json_pack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/main.dir/test_json_pack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_json_pack.cpp.o -c /data/code/main/test_json_pack.cpp

CMakeFiles/main.dir/test_json_pack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_json_pack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_json_pack.cpp > CMakeFiles/main.dir/test_json_pack.cpp.i

CMakeFiles/main.dir/test_json_pack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_json_pack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_json_pack.cpp -o CMakeFiles/main.dir/test_json_pack.cpp.s

CMakeFiles/main.dir/test_m_list.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_m_list.cpp.o: test_m_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/main.dir/test_m_list.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_m_list.cpp.o -c /data/code/main/test_m_list.cpp

CMakeFiles/main.dir/test_m_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_m_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_m_list.cpp > CMakeFiles/main.dir/test_m_list.cpp.i

CMakeFiles/main.dir/test_m_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_m_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_m_list.cpp -o CMakeFiles/main.dir/test_m_list.cpp.s

CMakeFiles/main.dir/test_map.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_map.cpp.o: test_map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/main.dir/test_map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_map.cpp.o -c /data/code/main/test_map.cpp

CMakeFiles/main.dir/test_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_map.cpp > CMakeFiles/main.dir/test_map.cpp.i

CMakeFiles/main.dir/test_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_map.cpp -o CMakeFiles/main.dir/test_map.cpp.s

CMakeFiles/main.dir/test_popen.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_popen.cpp.o: test_popen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/main.dir/test_popen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_popen.cpp.o -c /data/code/main/test_popen.cpp

CMakeFiles/main.dir/test_popen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_popen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_popen.cpp > CMakeFiles/main.dir/test_popen.cpp.i

CMakeFiles/main.dir/test_popen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_popen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_popen.cpp -o CMakeFiles/main.dir/test_popen.cpp.s

CMakeFiles/main.dir/test_ptr.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_ptr.cpp.o: test_ptr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/main.dir/test_ptr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_ptr.cpp.o -c /data/code/main/test_ptr.cpp

CMakeFiles/main.dir/test_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_ptr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_ptr.cpp > CMakeFiles/main.dir/test_ptr.cpp.i

CMakeFiles/main.dir/test_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_ptr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_ptr.cpp -o CMakeFiles/main.dir/test_ptr.cpp.s

CMakeFiles/main.dir/test_rand.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_rand.cpp.o: test_rand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/main.dir/test_rand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_rand.cpp.o -c /data/code/main/test_rand.cpp

CMakeFiles/main.dir/test_rand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_rand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_rand.cpp > CMakeFiles/main.dir/test_rand.cpp.i

CMakeFiles/main.dir/test_rand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_rand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_rand.cpp -o CMakeFiles/main.dir/test_rand.cpp.s

CMakeFiles/main.dir/test_state_mechine.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_state_mechine.cpp.o: test_state_mechine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/main.dir/test_state_mechine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_state_mechine.cpp.o -c /data/code/main/test_state_mechine.cpp

CMakeFiles/main.dir/test_state_mechine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_state_mechine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_state_mechine.cpp > CMakeFiles/main.dir/test_state_mechine.cpp.i

CMakeFiles/main.dir/test_state_mechine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_state_mechine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_state_mechine.cpp -o CMakeFiles/main.dir/test_state_mechine.cpp.s

CMakeFiles/main.dir/test_template.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_template.cpp.o: test_template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/main.dir/test_template.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_template.cpp.o -c /data/code/main/test_template.cpp

CMakeFiles/main.dir/test_template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_template.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_template.cpp > CMakeFiles/main.dir/test_template.cpp.i

CMakeFiles/main.dir/test_template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_template.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_template.cpp -o CMakeFiles/main.dir/test_template.cpp.s

CMakeFiles/main.dir/test_test.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_test.cpp.o: test_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building CXX object CMakeFiles/main.dir/test_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_test.cpp.o -c /data/code/main/test_test.cpp

CMakeFiles/main.dir/test_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_test.cpp > CMakeFiles/main.dir/test_test.cpp.i

CMakeFiles/main.dir/test_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_test.cpp -o CMakeFiles/main.dir/test_test.cpp.s

CMakeFiles/main.dir/test_timer.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_timer.cpp.o: test_timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Building CXX object CMakeFiles/main.dir/test_timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_timer.cpp.o -c /data/code/main/test_timer.cpp

CMakeFiles/main.dir/test_timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_timer.cpp > CMakeFiles/main.dir/test_timer.cpp.i

CMakeFiles/main.dir/test_timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_timer.cpp -o CMakeFiles/main.dir/test_timer.cpp.s

CMakeFiles/main.dir/test_tree.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_tree.cpp.o: test_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_25) "Building CXX object CMakeFiles/main.dir/test_tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_tree.cpp.o -c /data/code/main/test_tree.cpp

CMakeFiles/main.dir/test_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_tree.cpp > CMakeFiles/main.dir/test_tree.cpp.i

CMakeFiles/main.dir/test_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_tree.cpp -o CMakeFiles/main.dir/test_tree.cpp.s

CMakeFiles/main.dir/test_uv.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test_uv.cpp.o: test_uv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_26) "Building CXX object CMakeFiles/main.dir/test_uv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test_uv.cpp.o -c /data/code/main/test_uv.cpp

CMakeFiles/main.dir/test_uv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test_uv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/code/main/test_uv.cpp > CMakeFiles/main.dir/test_uv.cpp.i

CMakeFiles/main.dir/test_uv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test_uv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/code/main/test_uv.cpp -o CMakeFiles/main.dir/test_uv.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/base.cpp.o" \
"CMakeFiles/main.dir/cache.cpp.o" \
"CMakeFiles/main.dir/coroutine_test.cpp.o" \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/rank_rbtree.cpp.o" \
"CMakeFiles/main.dir/rank_skip_list.cpp.o" \
"CMakeFiles/main.dir/rank_test.cpp.o" \
"CMakeFiles/main.dir/redis_test.cpp.o" \
"CMakeFiles/main.dir/socket_test.cpp.o" \
"CMakeFiles/main.dir/test_aes_cbc.cpp.o" \
"CMakeFiles/main.dir/test_auto_ptr.cpp.o" \
"CMakeFiles/main.dir/test_bt.cpp.o" \
"CMakeFiles/main.dir/test_comp.cpp.o" \
"CMakeFiles/main.dir/test_function.cpp.o" \
"CMakeFiles/main.dir/test_json_pack.cpp.o" \
"CMakeFiles/main.dir/test_m_list.cpp.o" \
"CMakeFiles/main.dir/test_map.cpp.o" \
"CMakeFiles/main.dir/test_popen.cpp.o" \
"CMakeFiles/main.dir/test_ptr.cpp.o" \
"CMakeFiles/main.dir/test_rand.cpp.o" \
"CMakeFiles/main.dir/test_state_mechine.cpp.o" \
"CMakeFiles/main.dir/test_template.cpp.o" \
"CMakeFiles/main.dir/test_test.cpp.o" \
"CMakeFiles/main.dir/test_timer.cpp.o" \
"CMakeFiles/main.dir/test_tree.cpp.o" \
"CMakeFiles/main.dir/test_uv.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/base.cpp.o
main: CMakeFiles/main.dir/cache.cpp.o
main: CMakeFiles/main.dir/coroutine_test.cpp.o
main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/rank_rbtree.cpp.o
main: CMakeFiles/main.dir/rank_skip_list.cpp.o
main: CMakeFiles/main.dir/rank_test.cpp.o
main: CMakeFiles/main.dir/redis_test.cpp.o
main: CMakeFiles/main.dir/socket_test.cpp.o
main: CMakeFiles/main.dir/test_aes_cbc.cpp.o
main: CMakeFiles/main.dir/test_auto_ptr.cpp.o
main: CMakeFiles/main.dir/test_bt.cpp.o
main: CMakeFiles/main.dir/test_comp.cpp.o
main: CMakeFiles/main.dir/test_function.cpp.o
main: CMakeFiles/main.dir/test_json_pack.cpp.o
main: CMakeFiles/main.dir/test_m_list.cpp.o
main: CMakeFiles/main.dir/test_map.cpp.o
main: CMakeFiles/main.dir/test_popen.cpp.o
main: CMakeFiles/main.dir/test_ptr.cpp.o
main: CMakeFiles/main.dir/test_rand.cpp.o
main: CMakeFiles/main.dir/test_state_mechine.cpp.o
main: CMakeFiles/main.dir/test_template.cpp.o
main: CMakeFiles/main.dir/test_test.cpp.o
main: CMakeFiles/main.dir/test_timer.cpp.o
main: CMakeFiles/main.dir/test_tree.cpp.o
main: CMakeFiles/main.dir/test_uv.cpp.o
main: CMakeFiles/main.dir/build.make
main: hiredishelp/libhiredishelp.a
main: coroutine/libcoroutine.a
main: /usr/lib64/libm.so
main: /usr/lib64/libdl.so
main: /usr/lib64/librt.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/code/main/CMakeFiles --progress-num=$(CMAKE_PROGRESS_27) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /data/code/main && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/code/main /data/code/main /data/code/main /data/code/main /data/code/main/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

