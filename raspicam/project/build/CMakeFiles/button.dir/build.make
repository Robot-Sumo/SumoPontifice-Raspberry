# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/raspicam/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/raspicam/project/build

# Include any dependencies generated for this target.
include CMakeFiles/button.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/button.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/button.dir/flags.make

CMakeFiles/button.dir/button.cpp.o: CMakeFiles/button.dir/flags.make
CMakeFiles/button.dir/button.cpp.o: ../button.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspicam/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/button.dir/button.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/button.dir/button.cpp.o -c /home/pi/raspicam/project/button.cpp

CMakeFiles/button.dir/button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/button.dir/button.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspicam/project/button.cpp > CMakeFiles/button.dir/button.cpp.i

CMakeFiles/button.dir/button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/button.dir/button.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspicam/project/button.cpp -o CMakeFiles/button.dir/button.cpp.s

CMakeFiles/button.dir/button.cpp.o.requires:

.PHONY : CMakeFiles/button.dir/button.cpp.o.requires

CMakeFiles/button.dir/button.cpp.o.provides: CMakeFiles/button.dir/button.cpp.o.requires
	$(MAKE) -f CMakeFiles/button.dir/build.make CMakeFiles/button.dir/button.cpp.o.provides.build
.PHONY : CMakeFiles/button.dir/button.cpp.o.provides

CMakeFiles/button.dir/button.cpp.o.provides.build: CMakeFiles/button.dir/button.cpp.o


# Object files for target button
button_OBJECTS = \
"CMakeFiles/button.dir/button.cpp.o"

# External object files for target button
button_EXTERNAL_OBJECTS =

button: CMakeFiles/button.dir/button.cpp.o
button: CMakeFiles/button.dir/build.make
button: /usr/local/lib/libwiringPi.so
button: CMakeFiles/button.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/raspicam/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable button"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/button.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/button.dir/build: button

.PHONY : CMakeFiles/button.dir/build

CMakeFiles/button.dir/requires: CMakeFiles/button.dir/button.cpp.o.requires

.PHONY : CMakeFiles/button.dir/requires

CMakeFiles/button.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/button.dir/cmake_clean.cmake
.PHONY : CMakeFiles/button.dir/clean

CMakeFiles/button.dir/depend:
	cd /home/pi/raspicam/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/raspicam/project /home/pi/raspicam/project /home/pi/raspicam/project/build /home/pi/raspicam/project/build /home/pi/raspicam/project/build/CMakeFiles/button.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/button.dir/depend
