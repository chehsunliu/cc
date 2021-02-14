project(snippet)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
  INTERFACE ${PROJECT_SOURCE_DIR}/include
)

# Unit tests

set(TEST_TARGET_NAME "test_${PROJECT_NAME}")

add_executable(${TEST_TARGET_NAME}
  ${PROJECT_SOURCE_DIR}/src/catch2_runner.cpp
  ${PROJECT_SOURCE_DIR}/src/io_tests.cpp
  ${PROJECT_SOURCE_DIR}/src/prime_tests.cpp
)

target_link_libraries(${TEST_TARGET_NAME}
  ${PROJECT_NAME}
  Catch2::Catch2
)

add_test("test_${PROJECT_NAME}" ${TEST_TARGET_NAME})
