cmake_minimum_required(VERSION "3.21.0" FATAL_ERROR)

project("BreakOut" VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Define CMake configuration values accessable by source code
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

# Options
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

#add_executable("${PROJECT_NAME}" "src/main.cpp")


# OpenGL & GLM
set(glm_DIR "C:/Program Files (x86)/glm/lib/cmake/glm")
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

# GLFW 
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(include/glfw-3.3.5)

# Other Libraries
add_subdirectory(include/KHR)
add_subdirectory(include/glad)
add_subdirectory(include/stb)

add_subdirectory(src)

# Link libraries to executable
target_link_libraries("${PROJECT_NAME}" glm::glm glfw opengl32 glad stb)

# Include directory containing "Config.h"
target_include_directories("${PROJECT_NAME}" PRIVATE "${PROJECT_BINARY_DIR}")

# Install EXE
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)