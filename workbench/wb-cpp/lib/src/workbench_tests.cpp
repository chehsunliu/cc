#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::Solution sol;

    int _nums[] = {1, 2, 3, 1};
    std::vector<int> nums(_nums, _nums + 4);

    REQUIRE(sol.containsNearbyDuplicate(nums, 3) == true);
}

TEST_CASE("example2") {
    wb::Solution sol;

    int _nums[] = {1, 0, 1, 1};
    std::vector<int> nums(_nums, _nums + 4);

    REQUIRE(sol.containsNearbyDuplicate(nums, 1) == true);
}

TEST_CASE("example3") {
    wb::Solution sol;

    int _nums[] = {1, 2, 3, 1, 2, 3};
    std::vector<int> nums(_nums, _nums + 6);

    REQUIRE(sol.containsNearbyDuplicate(nums, 2) == false);
}
