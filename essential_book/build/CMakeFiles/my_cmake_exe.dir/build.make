# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/study/cpp/cppcook/CPPcook/essential_book/chapter04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/study/cpp/cppcook/CPPcook/essential_book/build

# Include any dependencies generated for this target.
include CMakeFiles/my_cmake_exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_cmake_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_cmake_exe.dir/flags.make

CMakeFiles/my_cmake_exe.dir/Triangular.cpp.o: CMakeFiles/my_cmake_exe.dir/flags.make
CMakeFiles/my_cmake_exe.dir/Triangular.cpp.o: /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/Triangular.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/study/cpp/cppcook/CPPcook/essential_book/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_cmake_exe.dir/Triangular.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_cmake_exe.dir/Triangular.cpp.o -c /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/Triangular.cpp

CMakeFiles/my_cmake_exe.dir/Triangular.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_cmake_exe.dir/Triangular.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/Triangular.cpp > CMakeFiles/my_cmake_exe.dir/Triangular.cpp.i

CMakeFiles/my_cmake_exe.dir/Triangular.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_cmake_exe.dir/Triangular.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/Triangular.cpp -o CMakeFiles/my_cmake_exe.dir/Triangular.cpp.s

CMakeFiles/my_cmake_exe.dir/05_static.cpp.o: CMakeFiles/my_cmake_exe.dir/flags.make
CMakeFiles/my_cmake_exe.dir/05_static.cpp.o: /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/05_static.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/study/cpp/cppcook/CPPcook/essential_book/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_cmake_exe.dir/05_static.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_cmake_exe.dir/05_static.cpp.o -c /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/05_static.cpp

CMakeFiles/my_cmake_exe.dir/05_static.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_cmake_exe.dir/05_static.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/05_static.cpp > CMakeFiles/my_cmake_exe.dir/05_static.cpp.i

CMakeFiles/my_cmake_exe.dir/05_static.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_cmake_exe.dir/05_static.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/study/cpp/cppcook/CPPcook/essential_book/chapter04/05_static.cpp -o CMakeFiles/my_cmake_exe.dir/05_static.cpp.s

# Object files for target my_cmake_exe
my_cmake_exe_OBJECTS = \
"CMakeFiles/my_cmake_exe.dir/Triangular.cpp.o" \
"CMakeFiles/my_cmake_exe.dir/05_static.cpp.o"

# External object files for target my_cmake_exe
my_cmake_exe_EXTERNAL_OBJECTS =

my_cmake_exe: CMakeFiles/my_cmake_exe.dir/Triangular.cpp.o
my_cmake_exe: CMakeFiles/my_cmake_exe.dir/05_static.cpp.o
my_cmake_exe: CMakeFiles/my_cmake_exe.dir/build.make
my_cmake_exe: CMakeFiles/my_cmake_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/study/cpp/cppcook/CPPcook/essential_book/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable my_cmake_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_cmake_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_cmake_exe.dir/build: my_cmake_exe

.PHONY : CMakeFiles/my_cmake_exe.dir/build

CMakeFiles/my_cmake_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_cmake_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_cmake_exe.dir/clean

CMakeFiles/my_cmake_exe.dir/depend:
	cd /data/study/cpp/cppcook/CPPcook/essential_book/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/study/cpp/cppcook/CPPcook/essential_book/chapter04 /data/study/cpp/cppcook/CPPcook/essential_book/chapter04 /data/study/cpp/cppcook/CPPcook/essential_book/build /data/study/cpp/cppcook/CPPcook/essential_book/build /data/study/cpp/cppcook/CPPcook/essential_book/build/CMakeFiles/my_cmake_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_cmake_exe.dir/depend

