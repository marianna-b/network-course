# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /opt/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mariashka/uni/nets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariashka/uni/nets/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/nets.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/nets.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/nets.dir/flags.make

CMakeFiles/nets.dir/main.cpp.o: CMakeFiles/nets.dir/flags.make
CMakeFiles/nets.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/nets.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nets.dir/main.cpp.o -c /home/mariashka/uni/nets/main.cpp

CMakeFiles/nets.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nets.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariashka/uni/nets/main.cpp > CMakeFiles/nets.dir/main.cpp.i

CMakeFiles/nets.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nets.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariashka/uni/nets/main.cpp -o CMakeFiles/nets.dir/main.cpp.s

CMakeFiles/nets.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/nets.dir/main.cpp.o.requires

CMakeFiles/nets.dir/main.cpp.o.provides: CMakeFiles/nets.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/nets.dir/build.make CMakeFiles/nets.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/nets.dir/main.cpp.o.provides

CMakeFiles/nets.dir/main.cpp.o.provides.build: CMakeFiles/nets.dir/main.cpp.o


CMakeFiles/nets.dir/dns.cpp.o: CMakeFiles/nets.dir/flags.make
CMakeFiles/nets.dir/dns.cpp.o: ../dns.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/nets.dir/dns.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nets.dir/dns.cpp.o -c /home/mariashka/uni/nets/dns.cpp

CMakeFiles/nets.dir/dns.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nets.dir/dns.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariashka/uni/nets/dns.cpp > CMakeFiles/nets.dir/dns.cpp.i

CMakeFiles/nets.dir/dns.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nets.dir/dns.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariashka/uni/nets/dns.cpp -o CMakeFiles/nets.dir/dns.cpp.s

CMakeFiles/nets.dir/dns.cpp.o.requires:

.PHONY : CMakeFiles/nets.dir/dns.cpp.o.requires

CMakeFiles/nets.dir/dns.cpp.o.provides: CMakeFiles/nets.dir/dns.cpp.o.requires
	$(MAKE) -f CMakeFiles/nets.dir/build.make CMakeFiles/nets.dir/dns.cpp.o.provides.build
.PHONY : CMakeFiles/nets.dir/dns.cpp.o.provides

CMakeFiles/nets.dir/dns.cpp.o.provides.build: CMakeFiles/nets.dir/dns.cpp.o


CMakeFiles/nets.dir/consumer.cpp.o: CMakeFiles/nets.dir/flags.make
CMakeFiles/nets.dir/consumer.cpp.o: ../consumer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/nets.dir/consumer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nets.dir/consumer.cpp.o -c /home/mariashka/uni/nets/consumer.cpp

CMakeFiles/nets.dir/consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nets.dir/consumer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariashka/uni/nets/consumer.cpp > CMakeFiles/nets.dir/consumer.cpp.i

CMakeFiles/nets.dir/consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nets.dir/consumer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariashka/uni/nets/consumer.cpp -o CMakeFiles/nets.dir/consumer.cpp.s

CMakeFiles/nets.dir/consumer.cpp.o.requires:

.PHONY : CMakeFiles/nets.dir/consumer.cpp.o.requires

CMakeFiles/nets.dir/consumer.cpp.o.provides: CMakeFiles/nets.dir/consumer.cpp.o.requires
	$(MAKE) -f CMakeFiles/nets.dir/build.make CMakeFiles/nets.dir/consumer.cpp.o.provides.build
.PHONY : CMakeFiles/nets.dir/consumer.cpp.o.provides

CMakeFiles/nets.dir/consumer.cpp.o.provides.build: CMakeFiles/nets.dir/consumer.cpp.o


CMakeFiles/nets.dir/producer.cpp.o: CMakeFiles/nets.dir/flags.make
CMakeFiles/nets.dir/producer.cpp.o: ../producer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/nets.dir/producer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nets.dir/producer.cpp.o -c /home/mariashka/uni/nets/producer.cpp

CMakeFiles/nets.dir/producer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nets.dir/producer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariashka/uni/nets/producer.cpp > CMakeFiles/nets.dir/producer.cpp.i

CMakeFiles/nets.dir/producer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nets.dir/producer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariashka/uni/nets/producer.cpp -o CMakeFiles/nets.dir/producer.cpp.s

CMakeFiles/nets.dir/producer.cpp.o.requires:

.PHONY : CMakeFiles/nets.dir/producer.cpp.o.requires

CMakeFiles/nets.dir/producer.cpp.o.provides: CMakeFiles/nets.dir/producer.cpp.o.requires
	$(MAKE) -f CMakeFiles/nets.dir/build.make CMakeFiles/nets.dir/producer.cpp.o.provides.build
.PHONY : CMakeFiles/nets.dir/producer.cpp.o.provides

CMakeFiles/nets.dir/producer.cpp.o.provides.build: CMakeFiles/nets.dir/producer.cpp.o


CMakeFiles/nets.dir/utils.cpp.o: CMakeFiles/nets.dir/flags.make
CMakeFiles/nets.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/nets.dir/utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nets.dir/utils.cpp.o -c /home/mariashka/uni/nets/utils.cpp

CMakeFiles/nets.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nets.dir/utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariashka/uni/nets/utils.cpp > CMakeFiles/nets.dir/utils.cpp.i

CMakeFiles/nets.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nets.dir/utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariashka/uni/nets/utils.cpp -o CMakeFiles/nets.dir/utils.cpp.s

CMakeFiles/nets.dir/utils.cpp.o.requires:

.PHONY : CMakeFiles/nets.dir/utils.cpp.o.requires

CMakeFiles/nets.dir/utils.cpp.o.provides: CMakeFiles/nets.dir/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/nets.dir/build.make CMakeFiles/nets.dir/utils.cpp.o.provides.build
.PHONY : CMakeFiles/nets.dir/utils.cpp.o.provides

CMakeFiles/nets.dir/utils.cpp.o.provides.build: CMakeFiles/nets.dir/utils.cpp.o


CMakeFiles/nets.dir/dns_entry.cpp.o: CMakeFiles/nets.dir/flags.make
CMakeFiles/nets.dir/dns_entry.cpp.o: ../dns_entry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/nets.dir/dns_entry.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nets.dir/dns_entry.cpp.o -c /home/mariashka/uni/nets/dns_entry.cpp

CMakeFiles/nets.dir/dns_entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nets.dir/dns_entry.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariashka/uni/nets/dns_entry.cpp > CMakeFiles/nets.dir/dns_entry.cpp.i

CMakeFiles/nets.dir/dns_entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nets.dir/dns_entry.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariashka/uni/nets/dns_entry.cpp -o CMakeFiles/nets.dir/dns_entry.cpp.s

CMakeFiles/nets.dir/dns_entry.cpp.o.requires:

.PHONY : CMakeFiles/nets.dir/dns_entry.cpp.o.requires

CMakeFiles/nets.dir/dns_entry.cpp.o.provides: CMakeFiles/nets.dir/dns_entry.cpp.o.requires
	$(MAKE) -f CMakeFiles/nets.dir/build.make CMakeFiles/nets.dir/dns_entry.cpp.o.provides.build
.PHONY : CMakeFiles/nets.dir/dns_entry.cpp.o.provides

CMakeFiles/nets.dir/dns_entry.cpp.o.provides.build: CMakeFiles/nets.dir/dns_entry.cpp.o


# Object files for target nets
nets_OBJECTS = \
"CMakeFiles/nets.dir/main.cpp.o" \
"CMakeFiles/nets.dir/dns.cpp.o" \
"CMakeFiles/nets.dir/consumer.cpp.o" \
"CMakeFiles/nets.dir/producer.cpp.o" \
"CMakeFiles/nets.dir/utils.cpp.o" \
"CMakeFiles/nets.dir/dns_entry.cpp.o"

# External object files for target nets
nets_EXTERNAL_OBJECTS =

nets: CMakeFiles/nets.dir/main.cpp.o
nets: CMakeFiles/nets.dir/dns.cpp.o
nets: CMakeFiles/nets.dir/consumer.cpp.o
nets: CMakeFiles/nets.dir/producer.cpp.o
nets: CMakeFiles/nets.dir/utils.cpp.o
nets: CMakeFiles/nets.dir/dns_entry.cpp.o
nets: CMakeFiles/nets.dir/build.make
nets: /usr/lib64/libboost_thread.so
nets: /usr/lib64/libboost_system.so
nets: CMakeFiles/nets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariashka/uni/nets/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable nets"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nets.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/nets.dir/build: nets

.PHONY : CMakeFiles/nets.dir/build

CMakeFiles/nets.dir/requires: CMakeFiles/nets.dir/main.cpp.o.requires
CMakeFiles/nets.dir/requires: CMakeFiles/nets.dir/dns.cpp.o.requires
CMakeFiles/nets.dir/requires: CMakeFiles/nets.dir/consumer.cpp.o.requires
CMakeFiles/nets.dir/requires: CMakeFiles/nets.dir/producer.cpp.o.requires
CMakeFiles/nets.dir/requires: CMakeFiles/nets.dir/utils.cpp.o.requires
CMakeFiles/nets.dir/requires: CMakeFiles/nets.dir/dns_entry.cpp.o.requires

.PHONY : CMakeFiles/nets.dir/requires

CMakeFiles/nets.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/nets.dir/cmake_clean.cmake
.PHONY : CMakeFiles/nets.dir/clean

CMakeFiles/nets.dir/depend:
	cd /home/mariashka/uni/nets/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariashka/uni/nets /home/mariashka/uni/nets /home/mariashka/uni/nets/cmake-build-debug /home/mariashka/uni/nets/cmake-build-debug /home/mariashka/uni/nets/cmake-build-debug/CMakeFiles/nets.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/nets.dir/depend

