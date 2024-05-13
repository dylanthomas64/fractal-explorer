cmake_minimum_required(VERSION 3.7)
project(SDL2Test)

#if you installed sdl without a package manager you may need to include a path to the library
list(APPEND CMAKE_PREFIX_PATH "C:/VSLib/SDL2-2.28.4")

find_package(SDL2 REQUIRED)

include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
include_directories(SDL2Test ${CMAKE_CURRENT_SOURCE_DIR}/headers/)


add_executable(SDL2Test ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Grid.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Fractal.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Renderer.cpp)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})