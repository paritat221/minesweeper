# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/onee/Documents/minesweeper/minesweeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/onee/Documents/minesweeper/minesweeper/build-cg

# Include any dependencies generated for this target.
include CMakeFiles/myaddin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myaddin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myaddin.dir/flags.make

CMakeFiles/myaddin.dir/src/main.c.obj: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myaddin.dir/src/main.c.obj"
	/home/onee/.local/bin/sh-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myaddin.dir/src/main.c.obj   -c /home/onee/Documents/minesweeper/minesweeper/src/main.c

CMakeFiles/myaddin.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myaddin.dir/src/main.c.i"
	/home/onee/.local/bin/sh-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/onee/Documents/minesweeper/minesweeper/src/main.c > CMakeFiles/myaddin.dir/src/main.c.i

CMakeFiles/myaddin.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myaddin.dir/src/main.c.s"
	/home/onee/.local/bin/sh-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/onee/Documents/minesweeper/minesweeper/src/main.c -o CMakeFiles/myaddin.dir/src/main.c.s

CMakeFiles/myaddin.dir/src/board.c.obj: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/src/board.c.obj: ../src/board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/myaddin.dir/src/board.c.obj"
	/home/onee/.local/bin/sh-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myaddin.dir/src/board.c.obj   -c /home/onee/Documents/minesweeper/minesweeper/src/board.c

CMakeFiles/myaddin.dir/src/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myaddin.dir/src/board.c.i"
	/home/onee/.local/bin/sh-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/onee/Documents/minesweeper/minesweeper/src/board.c > CMakeFiles/myaddin.dir/src/board.c.i

CMakeFiles/myaddin.dir/src/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myaddin.dir/src/board.c.s"
	/home/onee/.local/bin/sh-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/onee/Documents/minesweeper/minesweeper/src/board.c -o CMakeFiles/myaddin.dir/src/board.c.s

CMakeFiles/myaddin.dir/assets-cg/example.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/example.png: ../assets-cg/example.png
CMakeFiles/myaddin.dir/assets-cg/example.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/example.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/example.png -o CMakeFiles/myaddin.dir/assets-cg/example.png --toolchain=sh-elf --cg

CMakeFiles/myaddin.dir/assets-cg/desert_cell.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/desert_cell.png: ../assets-cg/desert_cell.png
CMakeFiles/myaddin.dir/assets-cg/desert_cell.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/desert_cell.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/desert_cell.png -o CMakeFiles/myaddin.dir/assets-cg/desert_cell.png --toolchain=sh-elf --cg

CMakeFiles/myaddin.dir/assets-cg/cursor.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/cursor.png: ../assets-cg/cursor.png
CMakeFiles/myaddin.dir/assets-cg/cursor.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/cursor.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/cursor.png -o CMakeFiles/myaddin.dir/assets-cg/cursor.png --toolchain=sh-elf --cg

CMakeFiles/myaddin.dir/assets-cg/flag.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/flag.png: ../assets-cg/flag.png
CMakeFiles/myaddin.dir/assets-cg/flag.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/flag.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/flag.png -o CMakeFiles/myaddin.dir/assets-cg/flag.png --toolchain=sh-elf --cg

CMakeFiles/myaddin.dir/assets-cg/nums.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/nums.png: ../assets-cg/nums.png
CMakeFiles/myaddin.dir/assets-cg/nums.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/nums.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/nums.png -o CMakeFiles/myaddin.dir/assets-cg/nums.png --toolchain=sh-elf --cg

CMakeFiles/myaddin.dir/assets-cg/bomb.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/bomb.png: ../assets-cg/bomb.png
CMakeFiles/myaddin.dir/assets-cg/bomb.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/bomb.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/bomb.png -o CMakeFiles/myaddin.dir/assets-cg/bomb.png --toolchain=sh-elf --cg

CMakeFiles/myaddin.dir/assets-cg/bugdenial.png: CMakeFiles/myaddin.dir/flags.make
CMakeFiles/myaddin.dir/assets-cg/bugdenial.png: ../assets-cg/bugdenial.png
CMakeFiles/myaddin.dir/assets-cg/bugdenial.png: ../assets-cg/fxconv-metadata.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building FXCONV object CMakeFiles/myaddin.dir/assets-cg/bugdenial.png"
	fxconv /home/onee/Documents/minesweeper/minesweeper/assets-cg/bugdenial.png -o CMakeFiles/myaddin.dir/assets-cg/bugdenial.png --toolchain=sh-elf --cg

# Object files for target myaddin
myaddin_OBJECTS = \
"CMakeFiles/myaddin.dir/src/main.c.obj" \
"CMakeFiles/myaddin.dir/src/board.c.obj" \
"CMakeFiles/myaddin.dir/assets-cg/example.png" \
"CMakeFiles/myaddin.dir/assets-cg/desert_cell.png" \
"CMakeFiles/myaddin.dir/assets-cg/cursor.png" \
"CMakeFiles/myaddin.dir/assets-cg/flag.png" \
"CMakeFiles/myaddin.dir/assets-cg/nums.png" \
"CMakeFiles/myaddin.dir/assets-cg/bomb.png" \
"CMakeFiles/myaddin.dir/assets-cg/bugdenial.png"

# External object files for target myaddin
myaddin_EXTERNAL_OBJECTS =

myaddin: CMakeFiles/myaddin.dir/src/main.c.obj
myaddin: CMakeFiles/myaddin.dir/src/board.c.obj
myaddin: CMakeFiles/myaddin.dir/assets-cg/example.png
myaddin: CMakeFiles/myaddin.dir/assets-cg/desert_cell.png
myaddin: CMakeFiles/myaddin.dir/assets-cg/cursor.png
myaddin: CMakeFiles/myaddin.dir/assets-cg/flag.png
myaddin: CMakeFiles/myaddin.dir/assets-cg/nums.png
myaddin: CMakeFiles/myaddin.dir/assets-cg/bomb.png
myaddin: CMakeFiles/myaddin.dir/assets-cg/bugdenial.png
myaddin: CMakeFiles/myaddin.dir/build.make
myaddin: /home/onee/.local/share/giteapc/Lephenixnoir/sh-elf-gcc/lib/gcc/sh3eb-elf/11.1.0/libgint-cg.a
myaddin: ../assets-cg/icon-uns.png
myaddin: ../assets-cg/icon-sel.png
myaddin: CMakeFiles/myaddin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable myaddin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myaddin.dir/link.txt --verbose=$(VERBOSE)
	/home/onee/.local/bin/sh-elf-objcopy -O binary -R .bss -R .gint_bss myaddin myaddin.bin
	mkg3a -n basic:Minesweeper -i uns:/home/onee/Documents/minesweeper/minesweeper/assets-cg/icon-uns.png -i sel:/home/onee/Documents/minesweeper/minesweeper/assets-cg/icon-sel.png myaddin.bin /home/onee/Documents/minesweeper/minesweeper/Minesweeper.g3a

# Rule to build all files generated by this target.
CMakeFiles/myaddin.dir/build: myaddin

.PHONY : CMakeFiles/myaddin.dir/build

CMakeFiles/myaddin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myaddin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myaddin.dir/clean

CMakeFiles/myaddin.dir/depend:
	cd /home/onee/Documents/minesweeper/minesweeper/build-cg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/onee/Documents/minesweeper/minesweeper /home/onee/Documents/minesweeper/minesweeper /home/onee/Documents/minesweeper/minesweeper/build-cg /home/onee/Documents/minesweeper/minesweeper/build-cg /home/onee/Documents/minesweeper/minesweeper/build-cg/CMakeFiles/myaddin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myaddin.dir/depend

