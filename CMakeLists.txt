cmake_minimum_required(VERSION "3.21.0" FATAL_ERROR)

project("BreakOut" VERSION 0.1 LANGUAGES CXX C)

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
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# Generate cmake settings header file
configure_file("${PROJECT_NAME}Config.h.in" "${PROJECT_NAME}Config.h")

# Libraries
set(HELLO_L hello)
add_subdirectory("include/${HELLO_L}")
list(APPEND install_libs "${HELLO_L}")

set(STB_L stb)
add_subdirectory("include/${STB_L}")
list(APPEND install_libs "${STB_L}")

# Project EXE
add_executable("${PROJECT_NAME}" "src/main.cpp" "src/stb_imp.cpp")

# Link required libraries
#list(LENGTH install_libs list_length)
if (DEFINED install_libs)
	target_link_libraries("${PROJECT_NAME}" "${install_libs}")
endif()

target_include_directories("${PROJECT_NAME}" PUBLIC 
						   						 "${PROJECT_BINARY_DIR}" #Required for BreakOutConfig.h
						   						 )

# Install EXE
install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.h" DESTINATION include)