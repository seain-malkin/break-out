set(HEADER_FILES
	include/oglengine/Engine.h
)

set(SOURCE_FILES
	src/Engine.cpp
)

add_library(oglengine ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(oglengine PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(oglengine glfw glad)

target_include_directories(oglengine
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)