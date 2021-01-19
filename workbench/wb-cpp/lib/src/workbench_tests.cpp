#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::Solution sol;

    REQUIRE(sol.isHappy(19));
}

TEST_CASE("example2") {
    wb::Solution sol;

    REQUIRE(!sol.isHappy(2));
}
