#include "workbench/workbench.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("simple") {
    REQUIRE(nullptr == nullptr);
}
