project(hello VERSION 1.0)

set(SOURCES "src/${PROJECT_NAME}/Hello.cpp")
add_library("${PROJECT_NAME}" STATIC "${SOURCES}")

target_include_directories("${PROJECT_NAME}" INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_definitions("${PROJECT_NAME}" PUBLIC HELLO_VERSION="${${PROJECT_NAME}_VERSION_MAJOR}")

# Install library
install(TARGETS "${PROJECT_NAME}" DESTINATION lib)
install(FILES "src/${PROJECT_NAME}/Hello.h" DESTINATION include)