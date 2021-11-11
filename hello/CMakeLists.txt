set(LIB_HELLO "hello")
set(SOURCES "src/hello/Hello.cpp")

add_library("${LIB_HELLO}" "${SOURCES}")

target_include_directories("${LIB_HELLO}" INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_definitions("${LIB_HELLO}" PUBLIC HELLO_VERSION=1)

# Install library
install(TARGETS "${LIB_HELLO}" DESTINATION lib)
install(FILES src/"${LIB_HELLO}"/Hello.h DESTINATION include)