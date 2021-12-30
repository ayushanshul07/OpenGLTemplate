cmake_minimum_required(VERSION 3.0.0)
project(webgl)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

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

target_include_directories(webgl PUBLIC ${CMAKE_SOURCE_DIR}/include
                                        ${CMAKE_SOURCE_DIR}/include/vendor)

target_link_libraries(webgl PUBLIC OpenGL::GL GLEW::GLEW glfw)
