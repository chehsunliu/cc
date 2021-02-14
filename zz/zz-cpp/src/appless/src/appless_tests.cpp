#include <vector>

#include "catch2/catch.hpp"

#include "appless/appless.hpp"

appless::Solution sol;

TEST_CASE("GG #1") {
    std::vector<int> nums({-1, 2, 1, -4});
    REQUIRE(sol.threeSumClosest(nums, 1) == 2);
}

TEST_CASE("GG #2") {
    std::vector<int> nums({-1, 2, 1, -4});
    REQUIRE(sol.threeSumClosest(nums, 3) == 2);
}

TEST_CASE("GG #3") {
    std::vector<int> nums({-1, 2, 1, -4, 1, 6, 2});
    REQUIRE(sol.threeSumClosest(nums, 16) == 10);
}

TEST_CASE("GG #4") {
    std::vector<int> nums({-1, 2, 1, -4, 6, 4, 8, 1, 4, 8, -6});
    REQUIRE(sol.threeSumClosest(nums, 23) == 22);
}
