#include "wblib/wblib.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("simple") {
    int actual_result = wb::add(3, 4);

    REQUIRE(actual_result == 7);
}
