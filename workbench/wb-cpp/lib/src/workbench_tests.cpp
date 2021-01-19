#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("example1") {
    wb::Solution sol;

    REQUIRE(sol.countPrimes(10) == 4);
}

TEST_CASE("example2") {
    wb::Solution sol;

    REQUIRE(sol.countPrimes(0) == 0);
    REQUIRE(sol.countPrimes(1) == 0);
}
