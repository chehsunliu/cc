#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    wb::Solution sol;

    REQUIRE(sol.longestPalindrome("abccccdd") == 7);
}

TEST_CASE("GG #2") {
    wb::Solution sol;

    REQUIRE(sol.longestPalindrome("a") == 1);
}

TEST_CASE("GG #3") {
    wb::Solution sol;

    REQUIRE(sol.longestPalindrome("bb") == 2);
}
