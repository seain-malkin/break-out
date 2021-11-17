set(HEADER_FILES
    "include/oglasset/Shader.h"
)

set(SOURCE_FILES
    "src/Shader.cpp"
)

add_library(oglasset ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(oglasset
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        $CMAKE_CURRENT_SOURCE_DIR/src
)

target_link_libraries(oglasset glm::glm glad)