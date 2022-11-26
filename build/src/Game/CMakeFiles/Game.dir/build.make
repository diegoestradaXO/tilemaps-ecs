# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build

# Include any dependencies generated for this target.
include src/Game/CMakeFiles/Game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Game/CMakeFiles/Game.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Game/CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include src/Game/CMakeFiles/Game.dir/flags.make

src/Game/CMakeFiles/Game.dir/Game.cpp.o: src/Game/CMakeFiles/Game.dir/flags.make
src/Game/CMakeFiles/Game.dir/Game.cpp.o: ../src/Game/Game.cpp
src/Game/CMakeFiles/Game.dir/Game.cpp.o: src/Game/CMakeFiles/Game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Game/CMakeFiles/Game.dir/Game.cpp.o"
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Game/CMakeFiles/Game.dir/Game.cpp.o -MF CMakeFiles/Game.dir/Game.cpp.o.d -o CMakeFiles/Game.dir/Game.cpp.o -c /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/src/Game/Game.cpp

src/Game/CMakeFiles/Game.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/Game.cpp.i"
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/src/Game/Game.cpp > CMakeFiles/Game.dir/Game.cpp.i

src/Game/CMakeFiles/Game.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/Game.cpp.s"
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/src/Game/Game.cpp -o CMakeFiles/Game.dir/Game.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/Game.cpp.o"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

src/Game/libGame.a: src/Game/CMakeFiles/Game.dir/Game.cpp.o
src/Game/libGame.a: src/Game/CMakeFiles/Game.dir/build.make
src/Game/libGame.a: src/Game/CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libGame.a"
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game && $(CMAKE_COMMAND) -P CMakeFiles/Game.dir/cmake_clean_target.cmake
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Game/CMakeFiles/Game.dir/build: src/Game/libGame.a
.PHONY : src/Game/CMakeFiles/Game.dir/build

src/Game/CMakeFiles/Game.dir/clean:
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game && $(CMAKE_COMMAND) -P CMakeFiles/Game.dir/cmake_clean.cmake
.PHONY : src/Game/CMakeFiles/Game.dir/clean

src/Game/CMakeFiles/Game.dir/depend:
	cd /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/src/Game /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game /Users/diegoestrada/Documents/universidad/last-semester/game-engines/tilemaps/build/src/Game/CMakeFiles/Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Game/CMakeFiles/Game.dir/depend

