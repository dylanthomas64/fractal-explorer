cmake_minimum_required(VERSION 3.5)
project(fractal-explorer)

#if find_package fails you can provide the SDL library PATH
#list(APPEND CMAKE_PREFIX_PATH "@PATH@")

# 1. Look for a SDL2 package, 2. look for the SDL2 component and 3. fail if none can be found
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

# 1. Look for a SDL2 package, 2. Look for the SDL2maincomponent and 3. DO NOT fail when SDL2main is not available
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)


include_directories(fractal-explorer ${CMAKE_CURRENT_SOURCE_DIR}/headers/)

set(SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/")

add_executable(fractal-explorer ${SOURCE}/main.cpp ${SOURCE}/Grid.cpp ${SOURCE}/Fractal.cpp ${SOURCE}/Renderer.cpp)

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(fractal-explorer PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(fractal-explorer PRIVATE SDL2::SDL2)