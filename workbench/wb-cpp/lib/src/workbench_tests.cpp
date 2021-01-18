#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::Solution sol;

    int _numbers[] = {2, 7, 11, 15};
    std::vector<int> numbers(_numbers, _numbers + 4);
    std::vector<int> actual_results = sol.twoSum(numbers, 9);

    int _expected_results[] = {1, 2};
    std::vector<int> expected_results(_expected_results, _expected_results + 2);

    REQUIRE(actual_results == expected_results);
}

TEST_CASE("example2") {
    wb::Solution sol;

    int _numbers[] = {2, 3, 4};
    std::vector<int> numbers(_numbers, _numbers + 3);
    std::vector<int> actual_results = sol.twoSum(numbers, 6);

    int _expected_results[] = {1, 3};
    std::vector<int> expected_results(_expected_results, _expected_results + 2);

    REQUIRE(actual_results == expected_results);
}

TEST_CASE("example3") {
    wb::Solution sol;

    int _numbers[] = {-1, 0};
    std::vector<int> numbers(_numbers, _numbers + 2);
    std::vector<int> actual_results = sol.twoSum(numbers, -1);

    int _expected_results[] = {1, 2};
    std::vector<int> expected_results(_expected_results, _expected_results + 2);

    REQUIRE(actual_results == expected_results);
}
