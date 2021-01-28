project(nonapp)

add_library(${PROJECT_NAME} INTERFACE)

# Unit tests

set(TEST_TARGET_NAME "${PROJECT_NAME}_test")

add_executable(${TEST_TARGET_NAME}
    ${PROJECT_SOURCE_DIR}/tests_main.cpp
    ${PROJECT_SOURCE_DIR}/nonapp_tests.cpp
)

target_link_libraries(${TEST_TARGET_NAME}
    ${PROJECT_NAME}
    Catch2::Catch2
)

add_test(test_nonapp ${TEST_TARGET_NAME})
