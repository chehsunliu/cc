#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    int _nums[] = {-2, 0, 3, -5, 2, -1};
    std::vector<int> nums(_nums, _nums + 6);
    wb::NumArray *obj = new wb::NumArray(nums);

    REQUIRE(obj->sumRange(0, 2) == 1);
    REQUIRE(obj->sumRange(2, 5) == -1);
    REQUIRE(obj->sumRange(0, 5) == -3);
    REQUIRE(obj->sumRange(2, 3) == -2);
}