#include <vector>

#include "catch2/catch.hpp"

#include "appless.hpp"

appless::Solution sol;

TEST_CASE("GG #1") {
    int _nums[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::vector<int> nums(_nums, _nums + sizeof(_nums) / sizeof(_nums[0]));
    REQUIRE(sol.maxArea(nums) == 49);
}

TEST_CASE("GG #2") {
    int _nums[] = {1, 1};
    std::vector<int> nums(_nums, _nums + sizeof(_nums) / sizeof(_nums[0]));
    REQUIRE(sol.maxArea(nums) == 1);
}

TEST_CASE("GG #3") {
    int _nums[] = {4, 3, 2, 1, 4};
    std::vector<int> nums(_nums, _nums + sizeof(_nums) / sizeof(_nums[0]));
    REQUIRE(sol.maxArea(nums) == 16);
}

TEST_CASE("GG #4") {
    int _nums[] = {1, 2, 1};
    std::vector<int> nums(_nums, _nums + sizeof(_nums) / sizeof(_nums[0]));
    REQUIRE(sol.maxArea(nums) == 2);
}
