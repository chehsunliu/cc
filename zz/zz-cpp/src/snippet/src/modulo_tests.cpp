#include <vector>

#include "catch2/catch.hpp"

#include "snippet/modulo.hpp"

using namespace snippet::modulo;

TEST_CASE("Basic Arithmetic") {
    typedef ModuloNumber<int, 7> mint;
    mint a1 = 12;
    mint a2 = 13;

    SECTION("add") {
        REQUIRE(a1 + a2 == 4);
        REQUIRE(a1 + a2 != 5);
        REQUIRE(a1 + a2 == 25);
        REQUIRE(a1 + a2 != 26);
    }

    SECTION("subtract") {
        REQUIRE(a1 - a2 == 6);
        REQUIRE(a2 - a1 == 1);
    }

    SECTION("multiply") {
        REQUIRE(a1 * a2 == 2);
    }
}