cmake_minimum_required(VERSION 3.16)

project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

add_executable(raytracer
    src/main.cpp
    src/vec.cpp
    src/color.cpp
    src/ray.cpp
    src/sphere.cpp
    src/hittable_list.cpp
)

target_include_directories(raytracer PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)
