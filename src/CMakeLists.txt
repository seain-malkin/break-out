add_executable("${PROJECT_NAME}" main.cpp)

add_subdirectory(oglbuffer)

target_link_libraries("${PROJECT_NAME}" oglbuffer)