cmake_minimum_required(VERSION 3.0.0)
project(webgl)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_SOURCE_DIR}/src/IndexBuffer.cpp
    ${CMAKE_SOURCE_DIR}/src/Renderer.cpp
    ${CMAKE_SOURCE_DIR}/src/Shader.cpp
    ${CMAKE_SOURCE_DIR}/src/Texture.cpp
    ${CMAKE_SOURCE_DIR}/src/VertexArray.cpp
    ${CMAKE_SOURCE_DIR}/src/VertexBuffer.cpp
    ${CMAKE_SOURCE_DIR}/src/VertexBufferLayout.cpp)

add_executable(webgl ${SRC_FILES})

set_target_properties(webgl PROPERTIES SUFFIX ".html" CXX_STANDARD 11)

target_include_directories(webgl PUBLIC ${CMAKE_SOURCE_DIR}/include
                                        ${CMAKE_SOURCE_DIR}/include/vendor)

target_link_libraries(webgl PUBLIC GL GLEW glfw)

target_compile_options(webgl PUBLIC -g)
target_link_options(
  webgl
  PUBLIC
  -g
  -sUSE_GLFW=3
  -sGL_ASSERTIONS=1
  -sGL_DEBUG=1
  --preload-file
  ../assets
  -sMAX_WEBGL_VERSION=3
  -sMIN_WEBGL_VERSION=3
  -sFULL_ES3=1)
