cmake_minimum_required(VERSION 3.5)

project(wb-cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This line must be added before add_subdirectory.
enable_testing()

add_subdirectory(src/app)
add_subdirectory(src/nonapp)
add_subdirectory(src/snippet)
add_subdirectory(src/3rd_party/catch2)
