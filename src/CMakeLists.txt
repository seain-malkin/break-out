add_subdirectory(oglbuffer)
add_subdirectory(oglasset)

target_link_libraries("${PROJECT_NAME}" oglbuffer oglasset)