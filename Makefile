# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /data/code/main/CMakeFiles /data/code/main/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /data/code/main/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

#=============================================================================
# Target rules for targets named hiredishelp

# Build rule for target.
hiredishelp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hiredishelp
.PHONY : hiredishelp

# fast build rule for target.
hiredishelp/fast:
	$(MAKE) $(MAKESILENT) -f hiredishelp/CMakeFiles/hiredishelp.dir/build.make hiredishelp/CMakeFiles/hiredishelp.dir/build
.PHONY : hiredishelp/fast

#=============================================================================
# Target rules for targets named coroutine

# Build rule for target.
coroutine: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 coroutine
.PHONY : coroutine

# fast build rule for target.
coroutine/fast:
	$(MAKE) $(MAKESILENT) -f coroutine/CMakeFiles/coroutine.dir/build.make coroutine/CMakeFiles/coroutine.dir/build
.PHONY : coroutine/fast

base.o: base.cpp.o

.PHONY : base.o

# target to build an object file
base.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/base.cpp.o
.PHONY : base.cpp.o

base.i: base.cpp.i

.PHONY : base.i

# target to preprocess a source file
base.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/base.cpp.i
.PHONY : base.cpp.i

base.s: base.cpp.s

.PHONY : base.s

# target to generate assembly for a file
base.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/base.cpp.s
.PHONY : base.cpp.s

cache.o: cache.cpp.o

.PHONY : cache.o

# target to build an object file
cache.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cache.cpp.o
.PHONY : cache.cpp.o

cache.i: cache.cpp.i

.PHONY : cache.i

# target to preprocess a source file
cache.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cache.cpp.i
.PHONY : cache.cpp.i

cache.s: cache.cpp.s

.PHONY : cache.s

# target to generate assembly for a file
cache.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/cache.cpp.s
.PHONY : cache.cpp.s

coroutine_test.o: coroutine_test.cpp.o

.PHONY : coroutine_test.o

# target to build an object file
coroutine_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/coroutine_test.cpp.o
.PHONY : coroutine_test.cpp.o

coroutine_test.i: coroutine_test.cpp.i

.PHONY : coroutine_test.i

# target to preprocess a source file
coroutine_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/coroutine_test.cpp.i
.PHONY : coroutine_test.cpp.i

coroutine_test.s: coroutine_test.cpp.s

.PHONY : coroutine_test.s

# target to generate assembly for a file
coroutine_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/coroutine_test.cpp.s
.PHONY : coroutine_test.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

redis_test.o: redis_test.cpp.o

.PHONY : redis_test.o

# target to build an object file
redis_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/redis_test.cpp.o
.PHONY : redis_test.cpp.o

redis_test.i: redis_test.cpp.i

.PHONY : redis_test.i

# target to preprocess a source file
redis_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/redis_test.cpp.i
.PHONY : redis_test.cpp.i

redis_test.s: redis_test.cpp.s

.PHONY : redis_test.s

# target to generate assembly for a file
redis_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/redis_test.cpp.s
.PHONY : redis_test.cpp.s

socket_test.o: socket_test.cpp.o

.PHONY : socket_test.o

# target to build an object file
socket_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/socket_test.cpp.o
.PHONY : socket_test.cpp.o

socket_test.i: socket_test.cpp.i

.PHONY : socket_test.i

# target to preprocess a source file
socket_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/socket_test.cpp.i
.PHONY : socket_test.cpp.i

socket_test.s: socket_test.cpp.s

.PHONY : socket_test.s

# target to generate assembly for a file
socket_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/socket_test.cpp.s
.PHONY : socket_test.cpp.s

test_aes_cbc.o: test_aes_cbc.cpp.o

.PHONY : test_aes_cbc.o

# target to build an object file
test_aes_cbc.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_aes_cbc.cpp.o
.PHONY : test_aes_cbc.cpp.o

test_aes_cbc.i: test_aes_cbc.cpp.i

.PHONY : test_aes_cbc.i

# target to preprocess a source file
test_aes_cbc.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_aes_cbc.cpp.i
.PHONY : test_aes_cbc.cpp.i

test_aes_cbc.s: test_aes_cbc.cpp.s

.PHONY : test_aes_cbc.s

# target to generate assembly for a file
test_aes_cbc.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_aes_cbc.cpp.s
.PHONY : test_aes_cbc.cpp.s

test_bt.o: test_bt.cpp.o

.PHONY : test_bt.o

# target to build an object file
test_bt.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_bt.cpp.o
.PHONY : test_bt.cpp.o

test_bt.i: test_bt.cpp.i

.PHONY : test_bt.i

# target to preprocess a source file
test_bt.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_bt.cpp.i
.PHONY : test_bt.cpp.i

test_bt.s: test_bt.cpp.s

.PHONY : test_bt.s

# target to generate assembly for a file
test_bt.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_bt.cpp.s
.PHONY : test_bt.cpp.s

test_json_pack.o: test_json_pack.cpp.o

.PHONY : test_json_pack.o

# target to build an object file
test_json_pack.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_json_pack.cpp.o
.PHONY : test_json_pack.cpp.o

test_json_pack.i: test_json_pack.cpp.i

.PHONY : test_json_pack.i

# target to preprocess a source file
test_json_pack.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_json_pack.cpp.i
.PHONY : test_json_pack.cpp.i

test_json_pack.s: test_json_pack.cpp.s

.PHONY : test_json_pack.s

# target to generate assembly for a file
test_json_pack.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_json_pack.cpp.s
.PHONY : test_json_pack.cpp.s

test_map.o: test_map.cpp.o

.PHONY : test_map.o

# target to build an object file
test_map.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_map.cpp.o
.PHONY : test_map.cpp.o

test_map.i: test_map.cpp.i

.PHONY : test_map.i

# target to preprocess a source file
test_map.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_map.cpp.i
.PHONY : test_map.cpp.i

test_map.s: test_map.cpp.s

.PHONY : test_map.s

# target to generate assembly for a file
test_map.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_map.cpp.s
.PHONY : test_map.cpp.s

test_popen.o: test_popen.cpp.o

.PHONY : test_popen.o

# target to build an object file
test_popen.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_popen.cpp.o
.PHONY : test_popen.cpp.o

test_popen.i: test_popen.cpp.i

.PHONY : test_popen.i

# target to preprocess a source file
test_popen.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_popen.cpp.i
.PHONY : test_popen.cpp.i

test_popen.s: test_popen.cpp.s

.PHONY : test_popen.s

# target to generate assembly for a file
test_popen.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_popen.cpp.s
.PHONY : test_popen.cpp.s

test_rbtree.o: test_rbtree.cpp.o

.PHONY : test_rbtree.o

# target to build an object file
test_rbtree.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_rbtree.cpp.o
.PHONY : test_rbtree.cpp.o

test_rbtree.i: test_rbtree.cpp.i

.PHONY : test_rbtree.i

# target to preprocess a source file
test_rbtree.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_rbtree.cpp.i
.PHONY : test_rbtree.cpp.i

test_rbtree.s: test_rbtree.cpp.s

.PHONY : test_rbtree.s

# target to generate assembly for a file
test_rbtree.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_rbtree.cpp.s
.PHONY : test_rbtree.cpp.s

test_state_mechine.o: test_state_mechine.cpp.o

.PHONY : test_state_mechine.o

# target to build an object file
test_state_mechine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_state_mechine.cpp.o
.PHONY : test_state_mechine.cpp.o

test_state_mechine.i: test_state_mechine.cpp.i

.PHONY : test_state_mechine.i

# target to preprocess a source file
test_state_mechine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_state_mechine.cpp.i
.PHONY : test_state_mechine.cpp.i

test_state_mechine.s: test_state_mechine.cpp.s

.PHONY : test_state_mechine.s

# target to generate assembly for a file
test_state_mechine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_state_mechine.cpp.s
.PHONY : test_state_mechine.cpp.s

test_template.o: test_template.cpp.o

.PHONY : test_template.o

# target to build an object file
test_template.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_template.cpp.o
.PHONY : test_template.cpp.o

test_template.i: test_template.cpp.i

.PHONY : test_template.i

# target to preprocess a source file
test_template.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_template.cpp.i
.PHONY : test_template.cpp.i

test_template.s: test_template.cpp.s

.PHONY : test_template.s

# target to generate assembly for a file
test_template.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_template.cpp.s
.PHONY : test_template.cpp.s

test_test.o: test_test.cpp.o

.PHONY : test_test.o

# target to build an object file
test_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_test.cpp.o
.PHONY : test_test.cpp.o

test_test.i: test_test.cpp.i

.PHONY : test_test.i

# target to preprocess a source file
test_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_test.cpp.i
.PHONY : test_test.cpp.i

test_test.s: test_test.cpp.s

.PHONY : test_test.s

# target to generate assembly for a file
test_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_test.cpp.s
.PHONY : test_test.cpp.s

test_tree.o: test_tree.cpp.o

.PHONY : test_tree.o

# target to build an object file
test_tree.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_tree.cpp.o
.PHONY : test_tree.cpp.o

test_tree.i: test_tree.cpp.i

.PHONY : test_tree.i

# target to preprocess a source file
test_tree.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_tree.cpp.i
.PHONY : test_tree.cpp.i

test_tree.s: test_tree.cpp.s

.PHONY : test_tree.s

# target to generate assembly for a file
test_tree.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/test_tree.cpp.s
.PHONY : test_tree.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... coroutine"
	@echo "... hiredishelp"
	@echo "... main"
	@echo "... base.o"
	@echo "... base.i"
	@echo "... base.s"
	@echo "... cache.o"
	@echo "... cache.i"
	@echo "... cache.s"
	@echo "... coroutine_test.o"
	@echo "... coroutine_test.i"
	@echo "... coroutine_test.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... redis_test.o"
	@echo "... redis_test.i"
	@echo "... redis_test.s"
	@echo "... socket_test.o"
	@echo "... socket_test.i"
	@echo "... socket_test.s"
	@echo "... test_aes_cbc.o"
	@echo "... test_aes_cbc.i"
	@echo "... test_aes_cbc.s"
	@echo "... test_bt.o"
	@echo "... test_bt.i"
	@echo "... test_bt.s"
	@echo "... test_json_pack.o"
	@echo "... test_json_pack.i"
	@echo "... test_json_pack.s"
	@echo "... test_map.o"
	@echo "... test_map.i"
	@echo "... test_map.s"
	@echo "... test_popen.o"
	@echo "... test_popen.i"
	@echo "... test_popen.s"
	@echo "... test_rbtree.o"
	@echo "... test_rbtree.i"
	@echo "... test_rbtree.s"
	@echo "... test_state_mechine.o"
	@echo "... test_state_mechine.i"
	@echo "... test_state_mechine.s"
	@echo "... test_template.o"
	@echo "... test_template.i"
	@echo "... test_template.s"
	@echo "... test_test.o"
	@echo "... test_test.i"
	@echo "... test_test.s"
	@echo "... test_tree.o"
	@echo "... test_tree.i"
	@echo "... test_tree.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

