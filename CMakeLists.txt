cmake_minimum_required(VERSION 3.10)
project(Ulam)

set(CMake_CXX_STANDARD 17)
set(CMake_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 11)
set(CMake_C_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRC_C src/*.c)
file(GLOB_RECURSE SRC_CPP src/*.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} include)

add_executable(Ulam ${SRC_C} ${SRC_CPP})
target_link_libraries(Ulam ${SDL2_LIBRARIES})