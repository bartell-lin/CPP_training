# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /Library/Frameworks/Python.framework/Versions/3.8/lib/python3.8/site-packages/cmake/data/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Library/Frameworks/Python.framework/Versions/3.8/lib/python3.8/site-packages/cmake/data/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bartell/SS/week2/Practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bartell/SS/week2/Practice/build

# Include any dependencies generated for this target.
include CMakeFiles/BigNumber.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BigNumber.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BigNumber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigNumber.dir/flags.make

CMakeFiles/BigNumber.dir/BigNumber.cpp.o: CMakeFiles/BigNumber.dir/flags.make
CMakeFiles/BigNumber.dir/BigNumber.cpp.o: ../BigNumber.cpp
CMakeFiles/BigNumber.dir/BigNumber.cpp.o: CMakeFiles/BigNumber.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bartell/SS/week2/Practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigNumber.dir/BigNumber.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BigNumber.dir/BigNumber.cpp.o -MF CMakeFiles/BigNumber.dir/BigNumber.cpp.o.d -o CMakeFiles/BigNumber.dir/BigNumber.cpp.o -c /Users/bartell/SS/week2/Practice/BigNumber.cpp

CMakeFiles/BigNumber.dir/BigNumber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigNumber.dir/BigNumber.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bartell/SS/week2/Practice/BigNumber.cpp > CMakeFiles/BigNumber.dir/BigNumber.cpp.i

CMakeFiles/BigNumber.dir/BigNumber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigNumber.dir/BigNumber.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bartell/SS/week2/Practice/BigNumber.cpp -o CMakeFiles/BigNumber.dir/BigNumber.cpp.s

# Object files for target BigNumber
BigNumber_OBJECTS = \
"CMakeFiles/BigNumber.dir/BigNumber.cpp.o"

# External object files for target BigNumber
BigNumber_EXTERNAL_OBJECTS =

libBigNumber.a: CMakeFiles/BigNumber.dir/BigNumber.cpp.o
libBigNumber.a: CMakeFiles/BigNumber.dir/build.make
libBigNumber.a: CMakeFiles/BigNumber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bartell/SS/week2/Practice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBigNumber.a"
	$(CMAKE_COMMAND) -P CMakeFiles/BigNumber.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigNumber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigNumber.dir/build: libBigNumber.a
.PHONY : CMakeFiles/BigNumber.dir/build

CMakeFiles/BigNumber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BigNumber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BigNumber.dir/clean

CMakeFiles/BigNumber.dir/depend:
	cd /Users/bartell/SS/week2/Practice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bartell/SS/week2/Practice /Users/bartell/SS/week2/Practice /Users/bartell/SS/week2/Practice/build /Users/bartell/SS/week2/Practice/build /Users/bartell/SS/week2/Practice/build/CMakeFiles/BigNumber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigNumber.dir/depend

