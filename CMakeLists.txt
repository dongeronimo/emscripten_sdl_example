cmake_minimum_required(VERSION 3.13)

project (hello_world_sdl)

include_directories("/home/luciano/emsdk/emsdk/emscripten/1.38.30/system/include")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXECUTABLE_SUFFIX ".html")
set (SOURCE_FILES "src/main.cpp")

add_executable(index ${SOURCE_FILES})
