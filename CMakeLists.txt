cmake_minimum_required(VERSION "3.21.0" FATAL_ERROR)

project("BreakOut" VERSION 0.1 LANGUAGES CXX C)

# Compiler Setup
add_library(breakout_compiler_flags INTERFACE)
target_compile_features(breakout_compiler_flags INTERFACE cxx_std_17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(breakout_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# Support IDE folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Generate cmake settings header file
configure_file("${PROJECT_NAME}Config.h.in" "${PROJECT_NAME}Config.h")

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(USE_HELLO "Use included hello implementation" ON)

# Include optional libraries
if (USE_HELLO)
	add_subdirectory(hello)
	list(APPEND EXTRA_LIBS hello)
endif()

# EXE
add_executable("${PROJECT_NAME}" "src/main.cpp")

# Link libraries and include directories
target_link_libraries("${PROJECT_NAME}" PUBLIC "${EXTRA_LIBS}")
target_include_directories("${PROJECT_NAME}" PUBLIC 
						   "${PROJECT_BINARY_DIR}" #Required for BreakOutConfig.h
						   )

# Install EXE
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)