cmake_minimum_required(VERSION 3.5)

project(zz-cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This line must be added before add_subdirectory.
enable_testing()

add_subdirectory(src/app)
add_subdirectory(src/appless)
add_subdirectory(src/codebook)
add_subdirectory(src/3rd_party/catch2)
