# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\webtech\profile

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\webtech\profile\build

# Utility rule file for ProfileApp_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/ProfileApp_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProfileApp_autogen.dir/progress.make

CMakeFiles/ProfileApp_autogen: ProfileApp_autogen/timestamp

ProfileApp_autogen/timestamp: C:/msys64/mingw64/share/qt6/bin/moc.exe
ProfileApp_autogen/timestamp: CMakeFiles/ProfileApp_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\webtech\profile\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target ProfileApp"
	C:\msys64\mingw64\bin\cmake.exe -E cmake_autogen C:/webtech/profile/build/CMakeFiles/ProfileApp_autogen.dir/AutogenInfo.json Release
	C:\msys64\mingw64\bin\cmake.exe -E touch C:/webtech/profile/build/ProfileApp_autogen/timestamp

CMakeFiles/ProfileApp_autogen.dir/codegen:
.PHONY : CMakeFiles/ProfileApp_autogen.dir/codegen

ProfileApp_autogen: CMakeFiles/ProfileApp_autogen
ProfileApp_autogen: ProfileApp_autogen/timestamp
ProfileApp_autogen: CMakeFiles/ProfileApp_autogen.dir/build.make
.PHONY : ProfileApp_autogen

# Rule to build all files generated by this target.
CMakeFiles/ProfileApp_autogen.dir/build: ProfileApp_autogen
.PHONY : CMakeFiles/ProfileApp_autogen.dir/build

CMakeFiles/ProfileApp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProfileApp_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProfileApp_autogen.dir/clean

CMakeFiles/ProfileApp_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\webtech\profile C:\webtech\profile C:\webtech\profile\build C:\webtech\profile\build C:\webtech\profile\build\CMakeFiles\ProfileApp_autogen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ProfileApp_autogen.dir/depend

