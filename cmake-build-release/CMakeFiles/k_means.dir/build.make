# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Users\Matteo\Dropbox\University\11\PC\k-means

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/k_means.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/k_means.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/k_means.dir/flags.make

CMakeFiles/k_means.dir/main.cpp.obj: CMakeFiles/k_means.dir/flags.make
CMakeFiles/k_means.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/k_means.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\k_means.dir\main.cpp.obj -c E:\Users\Matteo\Dropbox\University\11\PC\k-means\main.cpp

CMakeFiles/k_means.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k_means.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Users\Matteo\Dropbox\University\11\PC\k-means\main.cpp > CMakeFiles\k_means.dir\main.cpp.i

CMakeFiles/k_means.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k_means.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Users\Matteo\Dropbox\University\11\PC\k-means\main.cpp -o CMakeFiles\k_means.dir\main.cpp.s

CMakeFiles/k_means.dir/utils.cpp.obj: CMakeFiles/k_means.dir/flags.make
CMakeFiles/k_means.dir/utils.cpp.obj: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/k_means.dir/utils.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\k_means.dir\utils.cpp.obj -c E:\Users\Matteo\Dropbox\University\11\PC\k-means\utils.cpp

CMakeFiles/k_means.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/k_means.dir/utils.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Users\Matteo\Dropbox\University\11\PC\k-means\utils.cpp > CMakeFiles\k_means.dir\utils.cpp.i

CMakeFiles/k_means.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/k_means.dir/utils.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Users\Matteo\Dropbox\University\11\PC\k-means\utils.cpp -o CMakeFiles\k_means.dir\utils.cpp.s

# Object files for target k_means
k_means_OBJECTS = \
"CMakeFiles/k_means.dir/main.cpp.obj" \
"CMakeFiles/k_means.dir/utils.cpp.obj"

# External object files for target k_means
k_means_EXTERNAL_OBJECTS =

k_means.exe: CMakeFiles/k_means.dir/main.cpp.obj
k_means.exe: CMakeFiles/k_means.dir/utils.cpp.obj
k_means.exe: CMakeFiles/k_means.dir/build.make
k_means.exe: CMakeFiles/k_means.dir/linklibs.rsp
k_means.exe: CMakeFiles/k_means.dir/objects1.rsp
k_means.exe: CMakeFiles/k_means.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable k_means.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\k_means.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/k_means.dir/build: k_means.exe

.PHONY : CMakeFiles/k_means.dir/build

CMakeFiles/k_means.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\k_means.dir\cmake_clean.cmake
.PHONY : CMakeFiles/k_means.dir/clean

CMakeFiles/k_means.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Users\Matteo\Dropbox\University\11\PC\k-means E:\Users\Matteo\Dropbox\University\11\PC\k-means E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release E:\Users\Matteo\Dropbox\University\11\PC\k-means\cmake-build-release\CMakeFiles\k_means.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/k_means.dir/depend

