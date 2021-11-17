add_library(oglbuffer include/oglbuffer/ObjectBuffer.h)

set_target_properties(oglbuffer PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(oglbuffer
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(oglbuffer PRIVATE -Werror)
target_compile_features(oglbuffer PRIVATE cxx_std_11)