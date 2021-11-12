project(glm VERSION 1.0)

add_library("${PROJECT_NAME}" INTERFACE)
target_include_directories("${PROJECT_NAME}" INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Find all files in directory
FILE(GLOB h_glm "src/${PROJECT_NAME}/*")
FILE(GLOB h_detail "src/${PROJECT_NAME}/detail/*")
FILE(GLOB h_ext "src/${PROJECT_NAME}/ext/*")
FILE(GLOB h_gtc "src/${PROJECT_NAME}/gtc/*")
FILE(GLOB h_gtx "src/${PROJECT_NAME}/gtx/*")
FILE(GLOB h_simd "src/${PROJECT_NAME}/simd/*")


# Install library
install(TARGETS "${PROJECT_NAME}" DESTINATION lib)
install(FILES 
	"${h_glm}" 
	"${h_detail}"
	"${h_ext}"
	"${h_gtc}"
	"${h_gtx}"
	"${h_simd}"
	DESTINATION include)