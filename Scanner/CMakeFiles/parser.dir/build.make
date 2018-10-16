# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner

# Include any dependencies generated for this target.
include CMakeFiles/parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

quack.tab.cxx: quack.yxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating quack.tab.cxx, quack.tab.hxx, location.hh, position.hh, stack.hh"
	bison -d /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/quack.yxx

quack.tab.hxx: quack.tab.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate quack.tab.hxx

location.hh: quack.tab.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate location.hh

position.hh: quack.tab.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate position.hh

stack.hh: quack.tab.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate stack.hh

lex.yy.cpp: quack.lxx
lex.yy.cpp: quack.tab.hxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating lex.yy.cpp, lex.yy.h"
	reflex --bison-cc --bison-locations --header-file /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/quack.lxx

lex.yy.h: lex.yy.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate lex.yy.h

CMakeFiles/parser.dir/quack.tab.cxx.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/quack.tab.cxx.o: quack.tab.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/parser.dir/quack.tab.cxx.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/quack.tab.cxx.o -c /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/quack.tab.cxx

CMakeFiles/parser.dir/quack.tab.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/quack.tab.cxx.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/quack.tab.cxx > CMakeFiles/parser.dir/quack.tab.cxx.i

CMakeFiles/parser.dir/quack.tab.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/quack.tab.cxx.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/quack.tab.cxx -o CMakeFiles/parser.dir/quack.tab.cxx.s

CMakeFiles/parser.dir/lex.yy.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/lex.yy.cpp.o: lex.yy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/parser.dir/lex.yy.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/lex.yy.cpp.o -c /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/lex.yy.cpp

CMakeFiles/parser.dir/lex.yy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/lex.yy.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/lex.yy.cpp > CMakeFiles/parser.dir/lex.yy.cpp.i

CMakeFiles/parser.dir/lex.yy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/lex.yy.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/lex.yy.cpp -o CMakeFiles/parser.dir/lex.yy.cpp.s

CMakeFiles/parser.dir/parser.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/parser.cpp.o: parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/parser.dir/parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/parser.cpp.o -c /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/parser.cpp

CMakeFiles/parser.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/parser.cpp > CMakeFiles/parser.dir/parser.cpp.i

CMakeFiles/parser.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/parser.cpp -o CMakeFiles/parser.dir/parser.cpp.s

CMakeFiles/parser.dir/ASTNode.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/ASTNode.cpp.o: ASTNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/parser.dir/ASTNode.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/ASTNode.cpp.o -c /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/ASTNode.cpp

CMakeFiles/parser.dir/ASTNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/ASTNode.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/ASTNode.cpp > CMakeFiles/parser.dir/ASTNode.cpp.i

CMakeFiles/parser.dir/ASTNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/ASTNode.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/ASTNode.cpp -o CMakeFiles/parser.dir/ASTNode.cpp.s

CMakeFiles/parser.dir/Messages.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/Messages.cpp.o: Messages.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/parser.dir/Messages.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parser.dir/Messages.cpp.o -c /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/Messages.cpp

CMakeFiles/parser.dir/Messages.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/Messages.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/Messages.cpp > CMakeFiles/parser.dir/Messages.cpp.i

CMakeFiles/parser.dir/Messages.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/Messages.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/Messages.cpp -o CMakeFiles/parser.dir/Messages.cpp.s

# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/quack.tab.cxx.o" \
"CMakeFiles/parser.dir/lex.yy.cpp.o" \
"CMakeFiles/parser.dir/parser.cpp.o" \
"CMakeFiles/parser.dir/ASTNode.cpp.o" \
"CMakeFiles/parser.dir/Messages.cpp.o"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

parser: CMakeFiles/parser.dir/quack.tab.cxx.o
parser: CMakeFiles/parser.dir/lex.yy.cpp.o
parser: CMakeFiles/parser.dir/parser.cpp.o
parser: CMakeFiles/parser.dir/ASTNode.cpp.o
parser: CMakeFiles/parser.dir/Messages.cpp.o
parser: CMakeFiles/parser.dir/build.make
parser: /usr/local/lib/libreflex.a
parser: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser

.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend: quack.tab.cxx
CMakeFiles/parser.dir/depend: quack.tab.hxx
CMakeFiles/parser.dir/depend: location.hh
CMakeFiles/parser.dir/depend: position.hh
CMakeFiles/parser.dir/depend: stack.hh
CMakeFiles/parser.dir/depend: lex.yy.cpp
CMakeFiles/parser.dir/depend: lex.yy.h
	cd /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner /Users/alonzoaltamirano/Repos/Quack-Compiler/Scanner/CMakeFiles/parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend

