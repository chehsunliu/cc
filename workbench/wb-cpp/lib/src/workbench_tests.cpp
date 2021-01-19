#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::Solution sol;

    int _nums[] = {1, 2, 3, 1};
    std::vector<int> nums(_nums, _nums + 4);

    REQUIRE(sol.containsDuplicate(nums));
}

TEST_CASE("example2") {
    wb::Solution sol;

    int _nums[] = {1, 2, 3, 4};
    std::vector<int> nums(_nums, _nums + 4);

    REQUIRE(!sol.containsDuplicate(nums));
}

TEST_CASE("example3") {
    wb::Solution sol;

    int _nums[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::vector<int> nums(_nums, _nums + 10);

    REQUIRE(sol.containsDuplicate(nums));
}
