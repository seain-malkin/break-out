add_subdirectory(oglbuffer)
add_subdirectory(oglasset)
add_subdirectory(oglengine)

target_link_libraries("${PROJECT_NAME}" PRIVATE oglbuffer oglasset oglengine)