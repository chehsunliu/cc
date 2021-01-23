#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    wb::Solution sol;

    REQUIRE(sol.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
}

TEST_CASE("GG #2") {
    wb::Solution sol;

    REQUIRE(sol.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
}

TEST_CASE("GG #3") {
    wb::Solution sol;

    REQUIRE(sol.convert("A", 1) == "A");
}
