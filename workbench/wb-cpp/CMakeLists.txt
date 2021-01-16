cmake_minimum_required(VERSION 3.5)

project(wb-cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(wbbin)
add_subdirectory(wblib)
add_subdirectory(3rd_party/catch2)
