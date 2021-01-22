#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    wb::Solution sol;

    REQUIRE(sol.isPerfectSquare(16) == true);
    REQUIRE(sol.isPerfectSquare(1) == true);
    REQUIRE(sol.isPerfectSquare(4) == true);
    REQUIRE(sol.isPerfectSquare(2000105819) == false);
    REQUIRE(sol.isPerfectSquare(2) == false);
    REQUIRE(sol.isPerfectSquare(3) == false);
    REQUIRE(sol.isPerfectSquare(14) == false);
}
