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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dragomir/dev/A-star

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dragomir/dev/A-star/build

# Include any dependencies generated for this target.
include CMakeFiles/a-star.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/a-star.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a-star.dir/flags.make

CMakeFiles/a-star.dir/srcs/main.cpp.o: CMakeFiles/a-star.dir/flags.make
CMakeFiles/a-star.dir/srcs/main.cpp.o: ../srcs/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dragomir/dev/A-star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a-star.dir/srcs/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/a-star.dir/srcs/main.cpp.o -c /home/dragomir/dev/A-star/srcs/main.cpp

CMakeFiles/a-star.dir/srcs/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a-star.dir/srcs/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dragomir/dev/A-star/srcs/main.cpp > CMakeFiles/a-star.dir/srcs/main.cpp.i

CMakeFiles/a-star.dir/srcs/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a-star.dir/srcs/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dragomir/dev/A-star/srcs/main.cpp -o CMakeFiles/a-star.dir/srcs/main.cpp.s

# Object files for target a-star
a__star_OBJECTS = \
"CMakeFiles/a-star.dir/srcs/main.cpp.o"

# External object files for target a-star
a__star_EXTERNAL_OBJECTS =

a-star: CMakeFiles/a-star.dir/srcs/main.cpp.o
a-star: CMakeFiles/a-star.dir/build.make
a-star: CMakeFiles/a-star.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dragomir/dev/A-star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a-star"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/a-star.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a-star.dir/build: a-star

.PHONY : CMakeFiles/a-star.dir/build

CMakeFiles/a-star.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/a-star.dir/cmake_clean.cmake
.PHONY : CMakeFiles/a-star.dir/clean

CMakeFiles/a-star.dir/depend:
	cd /home/dragomir/dev/A-star/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dragomir/dev/A-star /home/dragomir/dev/A-star /home/dragomir/dev/A-star/build /home/dragomir/dev/A-star/build /home/dragomir/dev/A-star/build/CMakeFiles/a-star.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a-star.dir/depend

