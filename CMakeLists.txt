#1. Release: high optimization level, no debug info, code or asserts.
#2. Debug: No optimization, asserts enabled, [custom debug (output) code enabled],
#   debug info included in executable (so you can step through the code with a
#   debugger and have address to source-file:line-number translation).
#3. RelWithDebInfo: optimized, *with* debug info, but no debug (output) code or asserts.
#4. MinSizeRel: same as Release but optimizing for size rather than speed.



cmake_minimum_required(VERSION "3.21.0" FATAL_ERROR)

# BEGIN PROJECT
project("BreakOut" VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Generate cmake settings header file
configure_file("Config.h.in" "Config.h")

# Support IDE folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Compiler Setup
add_library(breakout_compiler_flags INTERFACE)
target_compile_features(breakout_compiler_flags INTERFACE cxx_std_17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(breakout_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# Project EXE
add_executable("${PROJECT_NAME}" "src/main.cpp")

# OpenGL
find_package(OpenGL REQUIRED)

# GLM
set(glm_DIR "C:/Program Files (x86)/glm/lib/cmake/glm")
find_package(GLM REQUIRED)
target_link_libraries("${PROJECT_NAME}" glm::glm)

# GLFW 
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory("include/glfw-3.3.5")

# GLAD & STB_IMAGE
add_library(STB_IMAGE "thirdparty/stb_image.cpp")
add_library(GLAD "thirdparty/glad.c")

# Link libraries to exec
#set(LIBS glfw opengl32 STB_IMAGE GLAD)
target_link_libraries("${PROJECT_NAME}" glfw opengl32 STB_IMAGE GLAD)

include_directories("${CMAKE_SOURCE_DIR}/include")
target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")
						   						 
# Install EXE
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)