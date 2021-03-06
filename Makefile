# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:
.PHONY : .NOTPARALLEL

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
CMAKE_SOURCE_DIR = /home/justus/Dokumente/college/cs40a/project01_team01/CMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/justus/Dokumente/college/cs40a/project01_team01

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/justus/Dokumente/college/cs40a/project01_team01/CMakeFiles /home/justus/Dokumente/college/cs40a/project01_team01/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/justus/Dokumente/college/cs40a/project01_team01/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Client

# Build rule for target.
Client: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Client
.PHONY : Client

# fast build rule for target.
Client/fast:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/build
.PHONY : Client/fast

#=============================================================================
# Target rules for targets named Core

# Build rule for target.
Core: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Core
.PHONY : Core

# fast build rule for target.
Core/fast:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/build
.PHONY : Core/fast

#=============================================================================
# Target rules for targets named Server

# Build rule for target.
Server: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Server
.PHONY : Server

# fast build rule for target.
Server/fast:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/build
.PHONY : Server/fast

Source/PhatChat/Client/Application.o: Source/PhatChat/Client/Application.cpp.o
.PHONY : Source/PhatChat/Client/Application.o

# target to build an object file
Source/PhatChat/Client/Application.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Application.cpp.o
.PHONY : Source/PhatChat/Client/Application.cpp.o

Source/PhatChat/Client/Application.i: Source/PhatChat/Client/Application.cpp.i
.PHONY : Source/PhatChat/Client/Application.i

# target to preprocess a source file
Source/PhatChat/Client/Application.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Application.cpp.i
.PHONY : Source/PhatChat/Client/Application.cpp.i

Source/PhatChat/Client/Application.s: Source/PhatChat/Client/Application.cpp.s
.PHONY : Source/PhatChat/Client/Application.s

# target to generate assembly for a file
Source/PhatChat/Client/Application.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Application.cpp.s
.PHONY : Source/PhatChat/Client/Application.cpp.s

Source/PhatChat/Client/ChatWindow.o: Source/PhatChat/Client/ChatWindow.cpp.o
.PHONY : Source/PhatChat/Client/ChatWindow.o

# target to build an object file
Source/PhatChat/Client/ChatWindow.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/ChatWindow.cpp.o
.PHONY : Source/PhatChat/Client/ChatWindow.cpp.o

Source/PhatChat/Client/ChatWindow.i: Source/PhatChat/Client/ChatWindow.cpp.i
.PHONY : Source/PhatChat/Client/ChatWindow.i

# target to preprocess a source file
Source/PhatChat/Client/ChatWindow.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/ChatWindow.cpp.i
.PHONY : Source/PhatChat/Client/ChatWindow.cpp.i

Source/PhatChat/Client/ChatWindow.s: Source/PhatChat/Client/ChatWindow.cpp.s
.PHONY : Source/PhatChat/Client/ChatWindow.s

# target to generate assembly for a file
Source/PhatChat/Client/ChatWindow.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/ChatWindow.cpp.s
.PHONY : Source/PhatChat/Client/ChatWindow.cpp.s

Source/PhatChat/Client/ConnectionWindow.o: Source/PhatChat/Client/ConnectionWindow.cpp.o
.PHONY : Source/PhatChat/Client/ConnectionWindow.o

# target to build an object file
Source/PhatChat/Client/ConnectionWindow.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/ConnectionWindow.cpp.o
.PHONY : Source/PhatChat/Client/ConnectionWindow.cpp.o

Source/PhatChat/Client/ConnectionWindow.i: Source/PhatChat/Client/ConnectionWindow.cpp.i
.PHONY : Source/PhatChat/Client/ConnectionWindow.i

# target to preprocess a source file
Source/PhatChat/Client/ConnectionWindow.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/ConnectionWindow.cpp.i
.PHONY : Source/PhatChat/Client/ConnectionWindow.cpp.i

Source/PhatChat/Client/ConnectionWindow.s: Source/PhatChat/Client/ConnectionWindow.cpp.s
.PHONY : Source/PhatChat/Client/ConnectionWindow.s

# target to generate assembly for a file
Source/PhatChat/Client/ConnectionWindow.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/ConnectionWindow.cpp.s
.PHONY : Source/PhatChat/Client/ConnectionWindow.cpp.s

Source/PhatChat/Client/Main.o: Source/PhatChat/Client/Main.cpp.o
.PHONY : Source/PhatChat/Client/Main.o

# target to build an object file
Source/PhatChat/Client/Main.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Main.cpp.o
.PHONY : Source/PhatChat/Client/Main.cpp.o

Source/PhatChat/Client/Main.i: Source/PhatChat/Client/Main.cpp.i
.PHONY : Source/PhatChat/Client/Main.i

# target to preprocess a source file
Source/PhatChat/Client/Main.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Main.cpp.i
.PHONY : Source/PhatChat/Client/Main.cpp.i

Source/PhatChat/Client/Main.s: Source/PhatChat/Client/Main.cpp.s
.PHONY : Source/PhatChat/Client/Main.s

# target to generate assembly for a file
Source/PhatChat/Client/Main.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Main.cpp.s
.PHONY : Source/PhatChat/Client/Main.cpp.s

Source/PhatChat/Client/Message.o: Source/PhatChat/Client/Message.cpp.o
.PHONY : Source/PhatChat/Client/Message.o

# target to build an object file
Source/PhatChat/Client/Message.cpp.o:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Message.cpp.o
.PHONY : Source/PhatChat/Client/Message.cpp.o

Source/PhatChat/Client/Message.i: Source/PhatChat/Client/Message.cpp.i
.PHONY : Source/PhatChat/Client/Message.i

# target to preprocess a source file
Source/PhatChat/Client/Message.cpp.i:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Message.cpp.i
.PHONY : Source/PhatChat/Client/Message.cpp.i

Source/PhatChat/Client/Message.s: Source/PhatChat/Client/Message.cpp.s
.PHONY : Source/PhatChat/Client/Message.s

# target to generate assembly for a file
Source/PhatChat/Client/Message.cpp.s:
	$(MAKE) -f CMakeFiles/Client.dir/build.make CMakeFiles/Client.dir/Source/PhatChat/Client/Message.cpp.s
.PHONY : Source/PhatChat/Client/Message.cpp.s

Source/PhatChat/Core/Application.o: Source/PhatChat/Core/Application.cpp.o
.PHONY : Source/PhatChat/Core/Application.o

# target to build an object file
Source/PhatChat/Core/Application.cpp.o:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/Application.cpp.o
.PHONY : Source/PhatChat/Core/Application.cpp.o

Source/PhatChat/Core/Application.i: Source/PhatChat/Core/Application.cpp.i
.PHONY : Source/PhatChat/Core/Application.i

# target to preprocess a source file
Source/PhatChat/Core/Application.cpp.i:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/Application.cpp.i
.PHONY : Source/PhatChat/Core/Application.cpp.i

Source/PhatChat/Core/Application.s: Source/PhatChat/Core/Application.cpp.s
.PHONY : Source/PhatChat/Core/Application.s

# target to generate assembly for a file
Source/PhatChat/Core/Application.cpp.s:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/Application.cpp.s
.PHONY : Source/PhatChat/Core/Application.cpp.s

Source/PhatChat/Core/MessagePacket.o: Source/PhatChat/Core/MessagePacket.cpp.o
.PHONY : Source/PhatChat/Core/MessagePacket.o

# target to build an object file
Source/PhatChat/Core/MessagePacket.cpp.o:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/MessagePacket.cpp.o
.PHONY : Source/PhatChat/Core/MessagePacket.cpp.o

Source/PhatChat/Core/MessagePacket.i: Source/PhatChat/Core/MessagePacket.cpp.i
.PHONY : Source/PhatChat/Core/MessagePacket.i

# target to preprocess a source file
Source/PhatChat/Core/MessagePacket.cpp.i:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/MessagePacket.cpp.i
.PHONY : Source/PhatChat/Core/MessagePacket.cpp.i

Source/PhatChat/Core/MessagePacket.s: Source/PhatChat/Core/MessagePacket.cpp.s
.PHONY : Source/PhatChat/Core/MessagePacket.s

# target to generate assembly for a file
Source/PhatChat/Core/MessagePacket.cpp.s:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/MessagePacket.cpp.s
.PHONY : Source/PhatChat/Core/MessagePacket.cpp.s

Source/PhatChat/Core/PingPacket.o: Source/PhatChat/Core/PingPacket.cpp.o
.PHONY : Source/PhatChat/Core/PingPacket.o

# target to build an object file
Source/PhatChat/Core/PingPacket.cpp.o:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/PingPacket.cpp.o
.PHONY : Source/PhatChat/Core/PingPacket.cpp.o

Source/PhatChat/Core/PingPacket.i: Source/PhatChat/Core/PingPacket.cpp.i
.PHONY : Source/PhatChat/Core/PingPacket.i

# target to preprocess a source file
Source/PhatChat/Core/PingPacket.cpp.i:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/PingPacket.cpp.i
.PHONY : Source/PhatChat/Core/PingPacket.cpp.i

Source/PhatChat/Core/PingPacket.s: Source/PhatChat/Core/PingPacket.cpp.s
.PHONY : Source/PhatChat/Core/PingPacket.s

# target to generate assembly for a file
Source/PhatChat/Core/PingPacket.cpp.s:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/PingPacket.cpp.s
.PHONY : Source/PhatChat/Core/PingPacket.cpp.s

Source/PhatChat/Core/PongPacket.o: Source/PhatChat/Core/PongPacket.cpp.o
.PHONY : Source/PhatChat/Core/PongPacket.o

# target to build an object file
Source/PhatChat/Core/PongPacket.cpp.o:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/PongPacket.cpp.o
.PHONY : Source/PhatChat/Core/PongPacket.cpp.o

Source/PhatChat/Core/PongPacket.i: Source/PhatChat/Core/PongPacket.cpp.i
.PHONY : Source/PhatChat/Core/PongPacket.i

# target to preprocess a source file
Source/PhatChat/Core/PongPacket.cpp.i:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/PongPacket.cpp.i
.PHONY : Source/PhatChat/Core/PongPacket.cpp.i

Source/PhatChat/Core/PongPacket.s: Source/PhatChat/Core/PongPacket.cpp.s
.PHONY : Source/PhatChat/Core/PongPacket.s

# target to generate assembly for a file
Source/PhatChat/Core/PongPacket.cpp.s:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/PongPacket.cpp.s
.PHONY : Source/PhatChat/Core/PongPacket.cpp.s

Source/PhatChat/Core/RequestUsernamePacket.o: Source/PhatChat/Core/RequestUsernamePacket.cpp.o
.PHONY : Source/PhatChat/Core/RequestUsernamePacket.o

# target to build an object file
Source/PhatChat/Core/RequestUsernamePacket.cpp.o:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/RequestUsernamePacket.cpp.o
.PHONY : Source/PhatChat/Core/RequestUsernamePacket.cpp.o

Source/PhatChat/Core/RequestUsernamePacket.i: Source/PhatChat/Core/RequestUsernamePacket.cpp.i
.PHONY : Source/PhatChat/Core/RequestUsernamePacket.i

# target to preprocess a source file
Source/PhatChat/Core/RequestUsernamePacket.cpp.i:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/RequestUsernamePacket.cpp.i
.PHONY : Source/PhatChat/Core/RequestUsernamePacket.cpp.i

Source/PhatChat/Core/RequestUsernamePacket.s: Source/PhatChat/Core/RequestUsernamePacket.cpp.s
.PHONY : Source/PhatChat/Core/RequestUsernamePacket.s

# target to generate assembly for a file
Source/PhatChat/Core/RequestUsernamePacket.cpp.s:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/RequestUsernamePacket.cpp.s
.PHONY : Source/PhatChat/Core/RequestUsernamePacket.cpp.s

Source/PhatChat/Core/ResponseUsernamePacket.o: Source/PhatChat/Core/ResponseUsernamePacket.cpp.o
.PHONY : Source/PhatChat/Core/ResponseUsernamePacket.o

# target to build an object file
Source/PhatChat/Core/ResponseUsernamePacket.cpp.o:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/ResponseUsernamePacket.cpp.o
.PHONY : Source/PhatChat/Core/ResponseUsernamePacket.cpp.o

Source/PhatChat/Core/ResponseUsernamePacket.i: Source/PhatChat/Core/ResponseUsernamePacket.cpp.i
.PHONY : Source/PhatChat/Core/ResponseUsernamePacket.i

# target to preprocess a source file
Source/PhatChat/Core/ResponseUsernamePacket.cpp.i:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/ResponseUsernamePacket.cpp.i
.PHONY : Source/PhatChat/Core/ResponseUsernamePacket.cpp.i

Source/PhatChat/Core/ResponseUsernamePacket.s: Source/PhatChat/Core/ResponseUsernamePacket.cpp.s
.PHONY : Source/PhatChat/Core/ResponseUsernamePacket.s

# target to generate assembly for a file
Source/PhatChat/Core/ResponseUsernamePacket.cpp.s:
	$(MAKE) -f CMakeFiles/Core.dir/build.make CMakeFiles/Core.dir/Source/PhatChat/Core/ResponseUsernamePacket.cpp.s
.PHONY : Source/PhatChat/Core/ResponseUsernamePacket.cpp.s

Source/PhatChat/Server/Application.o: Source/PhatChat/Server/Application.cpp.o
.PHONY : Source/PhatChat/Server/Application.o

# target to build an object file
Source/PhatChat/Server/Application.cpp.o:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Application.cpp.o
.PHONY : Source/PhatChat/Server/Application.cpp.o

Source/PhatChat/Server/Application.i: Source/PhatChat/Server/Application.cpp.i
.PHONY : Source/PhatChat/Server/Application.i

# target to preprocess a source file
Source/PhatChat/Server/Application.cpp.i:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Application.cpp.i
.PHONY : Source/PhatChat/Server/Application.cpp.i

Source/PhatChat/Server/Application.s: Source/PhatChat/Server/Application.cpp.s
.PHONY : Source/PhatChat/Server/Application.s

# target to generate assembly for a file
Source/PhatChat/Server/Application.cpp.s:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Application.cpp.s
.PHONY : Source/PhatChat/Server/Application.cpp.s

Source/PhatChat/Server/Client.o: Source/PhatChat/Server/Client.cpp.o
.PHONY : Source/PhatChat/Server/Client.o

# target to build an object file
Source/PhatChat/Server/Client.cpp.o:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Client.cpp.o
.PHONY : Source/PhatChat/Server/Client.cpp.o

Source/PhatChat/Server/Client.i: Source/PhatChat/Server/Client.cpp.i
.PHONY : Source/PhatChat/Server/Client.i

# target to preprocess a source file
Source/PhatChat/Server/Client.cpp.i:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Client.cpp.i
.PHONY : Source/PhatChat/Server/Client.cpp.i

Source/PhatChat/Server/Client.s: Source/PhatChat/Server/Client.cpp.s
.PHONY : Source/PhatChat/Server/Client.s

# target to generate assembly for a file
Source/PhatChat/Server/Client.cpp.s:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Client.cpp.s
.PHONY : Source/PhatChat/Server/Client.cpp.s

Source/PhatChat/Server/ClientManager.o: Source/PhatChat/Server/ClientManager.cpp.o
.PHONY : Source/PhatChat/Server/ClientManager.o

# target to build an object file
Source/PhatChat/Server/ClientManager.cpp.o:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/ClientManager.cpp.o
.PHONY : Source/PhatChat/Server/ClientManager.cpp.o

Source/PhatChat/Server/ClientManager.i: Source/PhatChat/Server/ClientManager.cpp.i
.PHONY : Source/PhatChat/Server/ClientManager.i

# target to preprocess a source file
Source/PhatChat/Server/ClientManager.cpp.i:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/ClientManager.cpp.i
.PHONY : Source/PhatChat/Server/ClientManager.cpp.i

Source/PhatChat/Server/ClientManager.s: Source/PhatChat/Server/ClientManager.cpp.s
.PHONY : Source/PhatChat/Server/ClientManager.s

# target to generate assembly for a file
Source/PhatChat/Server/ClientManager.cpp.s:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/ClientManager.cpp.s
.PHONY : Source/PhatChat/Server/ClientManager.cpp.s

Source/PhatChat/Server/Main.o: Source/PhatChat/Server/Main.cpp.o
.PHONY : Source/PhatChat/Server/Main.o

# target to build an object file
Source/PhatChat/Server/Main.cpp.o:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Main.cpp.o
.PHONY : Source/PhatChat/Server/Main.cpp.o

Source/PhatChat/Server/Main.i: Source/PhatChat/Server/Main.cpp.i
.PHONY : Source/PhatChat/Server/Main.i

# target to preprocess a source file
Source/PhatChat/Server/Main.cpp.i:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Main.cpp.i
.PHONY : Source/PhatChat/Server/Main.cpp.i

Source/PhatChat/Server/Main.s: Source/PhatChat/Server/Main.cpp.s
.PHONY : Source/PhatChat/Server/Main.s

# target to generate assembly for a file
Source/PhatChat/Server/Main.cpp.s:
	$(MAKE) -f CMakeFiles/Server.dir/build.make CMakeFiles/Server.dir/Source/PhatChat/Server/Main.cpp.s
.PHONY : Source/PhatChat/Server/Main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... Client"
	@echo "... Core"
	@echo "... Server"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Source/PhatChat/Client/Application.o"
	@echo "... Source/PhatChat/Client/Application.i"
	@echo "... Source/PhatChat/Client/Application.s"
	@echo "... Source/PhatChat/Client/ChatWindow.o"
	@echo "... Source/PhatChat/Client/ChatWindow.i"
	@echo "... Source/PhatChat/Client/ChatWindow.s"
	@echo "... Source/PhatChat/Client/ConnectionWindow.o"
	@echo "... Source/PhatChat/Client/ConnectionWindow.i"
	@echo "... Source/PhatChat/Client/ConnectionWindow.s"
	@echo "... Source/PhatChat/Client/Main.o"
	@echo "... Source/PhatChat/Client/Main.i"
	@echo "... Source/PhatChat/Client/Main.s"
	@echo "... Source/PhatChat/Client/Message.o"
	@echo "... Source/PhatChat/Client/Message.i"
	@echo "... Source/PhatChat/Client/Message.s"
	@echo "... Source/PhatChat/Core/Application.o"
	@echo "... Source/PhatChat/Core/Application.i"
	@echo "... Source/PhatChat/Core/Application.s"
	@echo "... Source/PhatChat/Core/MessagePacket.o"
	@echo "... Source/PhatChat/Core/MessagePacket.i"
	@echo "... Source/PhatChat/Core/MessagePacket.s"
	@echo "... Source/PhatChat/Core/PingPacket.o"
	@echo "... Source/PhatChat/Core/PingPacket.i"
	@echo "... Source/PhatChat/Core/PingPacket.s"
	@echo "... Source/PhatChat/Core/PongPacket.o"
	@echo "... Source/PhatChat/Core/PongPacket.i"
	@echo "... Source/PhatChat/Core/PongPacket.s"
	@echo "... Source/PhatChat/Core/RequestUsernamePacket.o"
	@echo "... Source/PhatChat/Core/RequestUsernamePacket.i"
	@echo "... Source/PhatChat/Core/RequestUsernamePacket.s"
	@echo "... Source/PhatChat/Core/ResponseUsernamePacket.o"
	@echo "... Source/PhatChat/Core/ResponseUsernamePacket.i"
	@echo "... Source/PhatChat/Core/ResponseUsernamePacket.s"
	@echo "... Source/PhatChat/Server/Application.o"
	@echo "... Source/PhatChat/Server/Application.i"
	@echo "... Source/PhatChat/Server/Application.s"
	@echo "... Source/PhatChat/Server/Client.o"
	@echo "... Source/PhatChat/Server/Client.i"
	@echo "... Source/PhatChat/Server/Client.s"
	@echo "... Source/PhatChat/Server/ClientManager.o"
	@echo "... Source/PhatChat/Server/ClientManager.i"
	@echo "... Source/PhatChat/Server/ClientManager.s"
	@echo "... Source/PhatChat/Server/Main.o"
	@echo "... Source/PhatChat/Server/Main.i"
	@echo "... Source/PhatChat/Server/Main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

