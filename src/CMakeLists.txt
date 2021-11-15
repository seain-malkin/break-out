add_executable("${PROJECT_NAME}" "main.cpp")
include_directories("${CMAKE_SOURCE_DIR}/include")

# OpenGL & GLM
set(glm_DIR "C:/Program Files (x86)/glm/lib/cmake/glm")
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

# GLFW 
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(
	"${CMAKE_SOURCE_DIR}/include/glfw-3.3.5" 
	"${CMAKE_SOURCE_DIR}/include/glfw-3.3.5"
	)

# GLAD & STB_IMAGE
add_library(STB_IMAGE "${CMAKE_SOURCE_DIR}/thirdparty/stb_image.cpp")
add_library(GLAD "${CMAKE_SOURCE_DIR}/thirdparty/glad.c")

# Link libraries to executable
target_link_libraries("${PROJECT_NAME}" glm::glm glfw opengl32 STB_IMAGE GLAD)