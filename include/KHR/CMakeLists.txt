add_library(khr INTERFACE)

set_target_properties(khr PROPERTIES LINKER_LANGUAGE C)

target_include_directories(khr
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)