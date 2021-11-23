set(HEADER_FILES
	include/oglbuffer/ObjectBuffer.h
	include/oglbuffer/VertexArray.h
	include/oglbuffer/VertexAttribute.h
)

set(SOURCE_FILES
	src/ObjectBuffer.cpp
	src/VertexArray.cpp
	src/VertexAttribute.cpp
)

add_library(oglbuffer STATIC ${SOURCE_FILES} ${HEADER_FILES})

set_target_properties(oglbuffer PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(oglbuffer glad)

target_include_directories(oglbuffer
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)