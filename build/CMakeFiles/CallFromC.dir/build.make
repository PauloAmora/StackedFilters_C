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
CMAKE_SOURCE_DIR = /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build

# Include any dependencies generated for this target.
include CMakeFiles/CallFromC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CallFromC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CallFromC.dir/flags.make

CMakeFiles/CallFromC.dir/CallFromC.c.o: CMakeFiles/CallFromC.dir/flags.make
CMakeFiles/CallFromC.dir/CallFromC.c.o: ../CallFromC.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CallFromC.dir/CallFromC.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CallFromC.dir/CallFromC.c.o   -c /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/CallFromC.c

CMakeFiles/CallFromC.dir/CallFromC.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CallFromC.dir/CallFromC.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/CallFromC.c > CMakeFiles/CallFromC.dir/CallFromC.c.i

CMakeFiles/CallFromC.dir/CallFromC.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CallFromC.dir/CallFromC.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/CallFromC.c -o CMakeFiles/CallFromC.dir/CallFromC.c.s

# Object files for target CallFromC
CallFromC_OBJECTS = \
"CMakeFiles/CallFromC.dir/CallFromC.c.o"

# External object files for target CallFromC
CallFromC_EXTERNAL_OBJECTS =

CallFromC: CMakeFiles/CallFromC.dir/CallFromC.c.o
CallFromC: CMakeFiles/CallFromC.dir/build.make
CallFromC: ../libs/libCallFromC.a
CallFromC: CMakeFiles/CallFromC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CallFromC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CallFromC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CallFromC.dir/build: CallFromC

.PHONY : CMakeFiles/CallFromC.dir/build

CMakeFiles/CallFromC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CallFromC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CallFromC.dir/clean

CMakeFiles/CallFromC.dir/depend:
	cd /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build /mnt/c/Users/Paulo/Desktop/pasta/sf_library_c/build/CMakeFiles/CallFromC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CallFromC.dir/depend

