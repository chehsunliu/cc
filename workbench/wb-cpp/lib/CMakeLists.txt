project (lib)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)

# Unit tests

set(TEST_TARGET_NAME "${PROJECT_NAME}_test")

add_executable(${TEST_TARGET_NAME} ${PROJECT_SOURCE_DIR}/src/workbench_tests.cpp)

target_link_libraries(${TEST_TARGET_NAME}
    ${PROJECT_NAME}
    Catch2::Catch2
)

add_test(test_workbench ${TEST_TARGET_NAME})
