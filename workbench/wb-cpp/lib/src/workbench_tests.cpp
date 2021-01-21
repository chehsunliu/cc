#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    wb::Solution sol;
    REQUIRE(sol.addDigits(38) == 2);
}
