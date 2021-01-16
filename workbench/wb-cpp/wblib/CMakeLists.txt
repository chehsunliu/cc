project (wblib)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)

# Unit tests

set(TEST_TARGET_NAME "${PROJECT_NAME}_test")

enable_testing()

add_executable(${TEST_TARGET_NAME} ${PROJECT_SOURCE_DIR}/src/wblib_tests.cpp)

target_link_libraries(${TEST_TARGET_NAME}
    ${PROJECT_NAME}
    Catch2::Test
)

add_test(test_all ${TEST_TARGET_NAME})
