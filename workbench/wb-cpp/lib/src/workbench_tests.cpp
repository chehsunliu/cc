#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "workbench/workbench.hpp"

TEST_CASE("GG #1") {
    wb::Solution sol;
    REQUIRE(sol.wordPattern("abba", "dog cat cat dog") == true);
}

TEST_CASE("GG #2") {
    wb::Solution sol;
    REQUIRE(sol.wordPattern("abba", "dog cat cat fish") == false);
}

TEST_CASE("GG #3") {
    wb::Solution sol;
    REQUIRE(sol.wordPattern("aaaa", "dog cat cat dog") == false);
}

TEST_CASE("GG #4") {
    wb::Solution sol;
    REQUIRE(sol.wordPattern("abba", "dog dog dog dog") == false);
}
