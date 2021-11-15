add_library(thirdparty stb_image.cpp glad.c)

target_include_directories(thirdparty PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>")