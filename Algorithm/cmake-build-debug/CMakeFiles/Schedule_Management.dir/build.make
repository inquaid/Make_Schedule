# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /home/turjo-pop/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/turjo-pop/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/turjo-pop/Documents/Make_Schedule/Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Schedule_Management.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Schedule_Management.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Schedule_Management.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Schedule_Management.dir/flags.make

CMakeFiles/Schedule_Management.dir/codegen:
.PHONY : CMakeFiles/Schedule_Management.dir/codegen

CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o: CMakeFiles/Schedule_Management.dir/flags.make
CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o: /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Teacher.cpp
CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o: CMakeFiles/Schedule_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o -MF CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o.d -o CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o -c /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Teacher.cpp

CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Teacher.cpp > CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.i

CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Teacher.cpp -o CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.s

CMakeFiles/Schedule_Management.dir/src/Course.cpp.o: CMakeFiles/Schedule_Management.dir/flags.make
CMakeFiles/Schedule_Management.dir/src/Course.cpp.o: /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Course.cpp
CMakeFiles/Schedule_Management.dir/src/Course.cpp.o: CMakeFiles/Schedule_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Schedule_Management.dir/src/Course.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Schedule_Management.dir/src/Course.cpp.o -MF CMakeFiles/Schedule_Management.dir/src/Course.cpp.o.d -o CMakeFiles/Schedule_Management.dir/src/Course.cpp.o -c /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Course.cpp

CMakeFiles/Schedule_Management.dir/src/Course.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Schedule_Management.dir/src/Course.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Course.cpp > CMakeFiles/Schedule_Management.dir/src/Course.cpp.i

CMakeFiles/Schedule_Management.dir/src/Course.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Schedule_Management.dir/src/Course.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Course.cpp -o CMakeFiles/Schedule_Management.dir/src/Course.cpp.s

CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o: CMakeFiles/Schedule_Management.dir/flags.make
CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o: /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/TimeSlot.cpp
CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o: CMakeFiles/Schedule_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o -MF CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o.d -o CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o -c /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/TimeSlot.cpp

CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/TimeSlot.cpp > CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.i

CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/TimeSlot.cpp -o CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.s

CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o: CMakeFiles/Schedule_Management.dir/flags.make
CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o: /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Schedule.cpp
CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o: CMakeFiles/Schedule_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o -MF CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o.d -o CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o -c /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Schedule.cpp

CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Schedule.cpp > CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.i

CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/Schedule.cpp -o CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.s

CMakeFiles/Schedule_Management.dir/src/main.cpp.o: CMakeFiles/Schedule_Management.dir/flags.make
CMakeFiles/Schedule_Management.dir/src/main.cpp.o: /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/main.cpp
CMakeFiles/Schedule_Management.dir/src/main.cpp.o: CMakeFiles/Schedule_Management.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Schedule_Management.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Schedule_Management.dir/src/main.cpp.o -MF CMakeFiles/Schedule_Management.dir/src/main.cpp.o.d -o CMakeFiles/Schedule_Management.dir/src/main.cpp.o -c /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/main.cpp

CMakeFiles/Schedule_Management.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Schedule_Management.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/main.cpp > CMakeFiles/Schedule_Management.dir/src/main.cpp.i

CMakeFiles/Schedule_Management.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Schedule_Management.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/turjo-pop/Documents/Make_Schedule/Algorithm/src/main.cpp -o CMakeFiles/Schedule_Management.dir/src/main.cpp.s

# Object files for target Schedule_Management
Schedule_Management_OBJECTS = \
"CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o" \
"CMakeFiles/Schedule_Management.dir/src/Course.cpp.o" \
"CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o" \
"CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o" \
"CMakeFiles/Schedule_Management.dir/src/main.cpp.o"

# External object files for target Schedule_Management
Schedule_Management_EXTERNAL_OBJECTS =

Schedule_Management: CMakeFiles/Schedule_Management.dir/src/Teacher.cpp.o
Schedule_Management: CMakeFiles/Schedule_Management.dir/src/Course.cpp.o
Schedule_Management: CMakeFiles/Schedule_Management.dir/src/TimeSlot.cpp.o
Schedule_Management: CMakeFiles/Schedule_Management.dir/src/Schedule.cpp.o
Schedule_Management: CMakeFiles/Schedule_Management.dir/src/main.cpp.o
Schedule_Management: CMakeFiles/Schedule_Management.dir/build.make
Schedule_Management: CMakeFiles/Schedule_Management.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Schedule_Management"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Schedule_Management.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Schedule_Management.dir/build: Schedule_Management
.PHONY : CMakeFiles/Schedule_Management.dir/build

CMakeFiles/Schedule_Management.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Schedule_Management.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Schedule_Management.dir/clean

CMakeFiles/Schedule_Management.dir/depend:
	cd /home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/turjo-pop/Documents/Make_Schedule/Algorithm /home/turjo-pop/Documents/Make_Schedule/Algorithm /home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug /home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug /home/turjo-pop/Documents/Make_Schedule/Algorithm/cmake-build-debug/CMakeFiles/Schedule_Management.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Schedule_Management.dir/depend

