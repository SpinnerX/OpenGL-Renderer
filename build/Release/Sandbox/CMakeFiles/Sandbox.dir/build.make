# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = C:\Users\heraa\.conan2\p\cmakefbe68aefa534a\p\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\heraa\.conan2\p\cmakefbe68aefa534a\p\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release

# Include any dependencies generated for this target.
include Sandbox/CMakeFiles/Sandbox.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Sandbox/CMakeFiles/Sandbox.dir/compiler_depend.make

# Include the progress variables for this target.
include Sandbox/CMakeFiles/Sandbox.dir/progress.make

# Include the compile flags for this target's objects.
include Sandbox/CMakeFiles/Sandbox.dir/flags.make

Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj: Sandbox/CMakeFiles/Sandbox.dir/flags.make
Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj: Sandbox/CMakeFiles/Sandbox.dir/includes_CXX.rsp
Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj: C:/Users/heraa/OneDrive/Desktop/OpenGL-Renderer/Sandbox/Application.cpp
Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj: Sandbox/CMakeFiles/Sandbox.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj"
	cd /d C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\Sandbox && C:\PROGRA~1\LLVM\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj -MF CMakeFiles\Sandbox.dir\Application.cpp.obj.d -o CMakeFiles\Sandbox.dir\Application.cpp.obj -c C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\Sandbox\Application.cpp

Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sandbox.dir/Application.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sandbox.dir/Application.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

# Object files for target Sandbox
Sandbox_OBJECTS = \
"CMakeFiles/Sandbox.dir/Application.cpp.obj"

# External object files for target Sandbox
Sandbox_EXTERNAL_OBJECTS =

Sandbox/Sandbox.exe: Sandbox/CMakeFiles/Sandbox.dir/Application.cpp.obj
Sandbox/Sandbox.exe: Sandbox/CMakeFiles/Sandbox.dir/build.make
Sandbox/Sandbox.exe: src/Renderer.lib
Sandbox/Sandbox.exe: C:/Users/heraa/.conan2/p/b/glfwf314a4a11e57e/p/lib/glfw3.lib
Sandbox/Sandbox.exe: C:/Users/heraa/.conan2/p/b/spdlod66d62668b266/p/lib/spdlog.lib
Sandbox/Sandbox.exe: C:/Users/heraa/.conan2/p/b/fmt64790ab8d786c/p/lib/fmt.lib
Sandbox/Sandbox.exe: C:/Users/heraa/.conan2/p/b/yaml-ded28610bf8e1/p/lib/yaml-cpp.lib
Sandbox/Sandbox.exe: Sandbox/CMakeFiles/Sandbox.dir/linkLibs.rsp
Sandbox/Sandbox.exe: Sandbox/CMakeFiles/Sandbox.dir/objects1.rsp
Sandbox/Sandbox.exe: Sandbox/CMakeFiles/Sandbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sandbox.exe"
	cd /d C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\Sandbox && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sandbox.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Sandbox/CMakeFiles/Sandbox.dir/build: Sandbox/Sandbox.exe
.PHONY : Sandbox/CMakeFiles/Sandbox.dir/build

Sandbox/CMakeFiles/Sandbox.dir/clean:
	cd /d C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\Sandbox && $(CMAKE_COMMAND) -P CMakeFiles\Sandbox.dir\cmake_clean.cmake
.PHONY : Sandbox/CMakeFiles/Sandbox.dir/clean

Sandbox/CMakeFiles/Sandbox.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\Sandbox C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\Sandbox C:\Users\heraa\OneDrive\Desktop\OpenGL-Renderer\build\Release\Sandbox\CMakeFiles\Sandbox.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : Sandbox/CMakeFiles/Sandbox.dir/depend

