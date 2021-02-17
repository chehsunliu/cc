#include <sstream>
#include <string>

#include "catch2/catch.hpp"

#include "snippet/modulo.hpp"

using namespace snippet::modulo;

typedef ModuloNumber<int, 7> mint7;

TEST_CASE("Small number arithmetic") {
    mint7 a1 = 12;
    mint7 a2 = 13;

    SECTION("add") {
        REQUIRE(a1 + a2 == 4);
        REQUIRE(a1 + a2 != 5);
        REQUIRE(a1 + a2 == 25);
        REQUIRE(a1 + a2 != 26);

        REQUIRE(a1++ == 5);
        REQUIRE(a1 == 6);
        REQUIRE(++a1 == 0);
        REQUIRE(a1 == 0);
    }

    SECTION("subtract") {
        REQUIRE(a1 - a2 == 6);
        REQUIRE(a2 - a1 == 1);
    }

    SECTION("multiply") { REQUIRE(a1 * a2 == 2); }
}

TEST_CASE("IO") {
    SECTION("Input") {
        std::string s = "23 26";
        std::istringstream stream(s);

        mint7 a1, a2;
        stream >> a1 >> a2;

        REQUIRE(a1 == 2);
        REQUIRE(a2 == 5);
    }

    SECTION("Output") {
        mint7 a1 = 23, a2 = 26;

        std::ostringstream stream;
        stream << a1 << " " << a2;
        REQUIRE(stream.str() == "<2 (mod 7)> <5 (mod 7)>");
    }
}