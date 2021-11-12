project(etc VERSION 1.0)

add_library("${PROJECT_NAME}" INTERFACE)
target_include_directories("${PROJECT_NAME}" INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Install library
install(TARGETS "${PROJECT_NAME}" DESTINATION lib)
install(FILES 
	"src/${PROJECT_NAME}/glad.h"
	"src/${PROJECT_NAME}/khrplatform.h"
	"src/${PROJECT_NAME}/stb_image.h"
	DESTINATION include)