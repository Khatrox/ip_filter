# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion_\CLion 2019.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion_\CLion 2019.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\xMellox\CLionProjects\ip_filter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\xMellox\CLionProjects\ip_filter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ip_filter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ip_filter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ip_filter.dir/flags.make

CMakeFiles/ip_filter.dir/main.cpp.obj: CMakeFiles/ip_filter.dir/flags.make
CMakeFiles/ip_filter.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xMellox\CLionProjects\ip_filter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ip_filter.dir/main.cpp.obj"
	D:\Mingw_\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ip_filter.dir\main.cpp.obj -c C:\Users\xMellox\CLionProjects\ip_filter\main.cpp

CMakeFiles/ip_filter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ip_filter.dir/main.cpp.i"
	D:\Mingw_\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xMellox\CLionProjects\ip_filter\main.cpp > CMakeFiles\ip_filter.dir\main.cpp.i

CMakeFiles/ip_filter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ip_filter.dir/main.cpp.s"
	D:\Mingw_\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xMellox\CLionProjects\ip_filter\main.cpp -o CMakeFiles\ip_filter.dir\main.cpp.s

# Object files for target ip_filter
ip_filter_OBJECTS = \
"CMakeFiles/ip_filter.dir/main.cpp.obj"

# External object files for target ip_filter
ip_filter_EXTERNAL_OBJECTS =

ip_filter.exe: CMakeFiles/ip_filter.dir/main.cpp.obj
ip_filter.exe: CMakeFiles/ip_filter.dir/build.make
ip_filter.exe: CMakeFiles/ip_filter.dir/linklibs.rsp
ip_filter.exe: CMakeFiles/ip_filter.dir/objects1.rsp
ip_filter.exe: CMakeFiles/ip_filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xMellox\CLionProjects\ip_filter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ip_filter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ip_filter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ip_filter.dir/build: ip_filter.exe

.PHONY : CMakeFiles/ip_filter.dir/build

CMakeFiles/ip_filter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ip_filter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ip_filter.dir/clean

CMakeFiles/ip_filter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xMellox\CLionProjects\ip_filter C:\Users\xMellox\CLionProjects\ip_filter C:\Users\xMellox\CLionProjects\ip_filter\cmake-build-debug C:\Users\xMellox\CLionProjects\ip_filter\cmake-build-debug C:\Users\xMellox\CLionProjects\ip_filter\cmake-build-debug\CMakeFiles\ip_filter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ip_filter.dir/depend
