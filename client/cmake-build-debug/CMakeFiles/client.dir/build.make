# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/zhoubin/ProjectOnGit/ChatRoom/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/main.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/main.cpp.o -c /home/zhoubin/ProjectOnGit/ChatRoom/client/main.cpp

CMakeFiles/client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoubin/ProjectOnGit/ChatRoom/client/main.cpp > CMakeFiles/client.dir/main.cpp.i

CMakeFiles/client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoubin/ProjectOnGit/ChatRoom/client/main.cpp -o CMakeFiles/client.dir/main.cpp.s

CMakeFiles/client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/main.cpp.o.requires

CMakeFiles/client.dir/main.cpp.o.provides: CMakeFiles/client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/main.cpp.o.provides

CMakeFiles/client.dir/main.cpp.o.provides.build: CMakeFiles/client.dir/main.cpp.o


CMakeFiles/client.dir/ClientMes.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/ClientMes.cpp.o: ../ClientMes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/ClientMes.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/ClientMes.cpp.o -c /home/zhoubin/ProjectOnGit/ChatRoom/client/ClientMes.cpp

CMakeFiles/client.dir/ClientMes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/ClientMes.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoubin/ProjectOnGit/ChatRoom/client/ClientMes.cpp > CMakeFiles/client.dir/ClientMes.cpp.i

CMakeFiles/client.dir/ClientMes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/ClientMes.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoubin/ProjectOnGit/ChatRoom/client/ClientMes.cpp -o CMakeFiles/client.dir/ClientMes.cpp.s

CMakeFiles/client.dir/ClientMes.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/ClientMes.cpp.o.requires

CMakeFiles/client.dir/ClientMes.cpp.o.provides: CMakeFiles/client.dir/ClientMes.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/ClientMes.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/ClientMes.cpp.o.provides

CMakeFiles/client.dir/ClientMes.cpp.o.provides.build: CMakeFiles/client.dir/ClientMes.cpp.o


CMakeFiles/client.dir/Client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/Client.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Client.cpp.o -c /home/zhoubin/ProjectOnGit/ChatRoom/client/Client.cpp

CMakeFiles/client.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Client.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoubin/ProjectOnGit/ChatRoom/client/Client.cpp > CMakeFiles/client.dir/Client.cpp.i

CMakeFiles/client.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Client.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoubin/ProjectOnGit/ChatRoom/client/Client.cpp -o CMakeFiles/client.dir/Client.cpp.s

CMakeFiles/client.dir/Client.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/Client.cpp.o.requires

CMakeFiles/client.dir/Client.cpp.o.provides: CMakeFiles/client.dir/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Client.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/Client.cpp.o.provides

CMakeFiles/client.dir/Client.cpp.o.provides.build: CMakeFiles/client.dir/Client.cpp.o


CMakeFiles/client.dir/ServerMes.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/ServerMes.cpp.o: ../ServerMes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/ServerMes.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/ServerMes.cpp.o -c /home/zhoubin/ProjectOnGit/ChatRoom/client/ServerMes.cpp

CMakeFiles/client.dir/ServerMes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/ServerMes.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoubin/ProjectOnGit/ChatRoom/client/ServerMes.cpp > CMakeFiles/client.dir/ServerMes.cpp.i

CMakeFiles/client.dir/ServerMes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/ServerMes.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoubin/ProjectOnGit/ChatRoom/client/ServerMes.cpp -o CMakeFiles/client.dir/ServerMes.cpp.s

CMakeFiles/client.dir/ServerMes.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/ServerMes.cpp.o.requires

CMakeFiles/client.dir/ServerMes.cpp.o.provides: CMakeFiles/client.dir/ServerMes.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/ServerMes.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/ServerMes.cpp.o.provides

CMakeFiles/client.dir/ServerMes.cpp.o.provides.build: CMakeFiles/client.dir/ServerMes.cpp.o


CMakeFiles/client.dir/md5.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/md5.cpp.o: ../md5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/client.dir/md5.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/md5.cpp.o -c /home/zhoubin/ProjectOnGit/ChatRoom/client/md5.cpp

CMakeFiles/client.dir/md5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/md5.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoubin/ProjectOnGit/ChatRoom/client/md5.cpp > CMakeFiles/client.dir/md5.cpp.i

CMakeFiles/client.dir/md5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/md5.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoubin/ProjectOnGit/ChatRoom/client/md5.cpp -o CMakeFiles/client.dir/md5.cpp.s

CMakeFiles/client.dir/md5.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/md5.cpp.o.requires

CMakeFiles/client.dir/md5.cpp.o.provides: CMakeFiles/client.dir/md5.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/md5.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/md5.cpp.o.provides

CMakeFiles/client.dir/md5.cpp.o.provides.build: CMakeFiles/client.dir/md5.cpp.o


CMakeFiles/client.dir/Functools.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/Functools.cpp.o: ../Functools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/client.dir/Functools.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/Functools.cpp.o -c /home/zhoubin/ProjectOnGit/ChatRoom/client/Functools.cpp

CMakeFiles/client.dir/Functools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/Functools.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoubin/ProjectOnGit/ChatRoom/client/Functools.cpp > CMakeFiles/client.dir/Functools.cpp.i

CMakeFiles/client.dir/Functools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/Functools.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoubin/ProjectOnGit/ChatRoom/client/Functools.cpp -o CMakeFiles/client.dir/Functools.cpp.s

CMakeFiles/client.dir/Functools.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/Functools.cpp.o.requires

CMakeFiles/client.dir/Functools.cpp.o.provides: CMakeFiles/client.dir/Functools.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/Functools.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/Functools.cpp.o.provides

CMakeFiles/client.dir/Functools.cpp.o.provides.build: CMakeFiles/client.dir/Functools.cpp.o


# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/main.cpp.o" \
"CMakeFiles/client.dir/ClientMes.cpp.o" \
"CMakeFiles/client.dir/Client.cpp.o" \
"CMakeFiles/client.dir/ServerMes.cpp.o" \
"CMakeFiles/client.dir/md5.cpp.o" \
"CMakeFiles/client.dir/Functools.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/main.cpp.o
client: CMakeFiles/client.dir/ClientMes.cpp.o
client: CMakeFiles/client.dir/Client.cpp.o
client: CMakeFiles/client.dir/ServerMes.cpp.o
client: CMakeFiles/client.dir/md5.cpp.o
client: CMakeFiles/client.dir/Functools.cpp.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/main.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/ClientMes.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/Client.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/ServerMes.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/md5.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/Functools.cpp.o.requires

.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhoubin/ProjectOnGit/ChatRoom/client /home/zhoubin/ProjectOnGit/ChatRoom/client /home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug /home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug /home/zhoubin/ProjectOnGit/ChatRoom/client/cmake-build-debug/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

