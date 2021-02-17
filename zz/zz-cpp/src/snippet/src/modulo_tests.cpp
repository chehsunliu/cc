#include <sstream>
#include <string>

#include "catch2/catch.hpp"

#include "snippet/modulo.hpp"

using namespace snippet::modulo;

typedef ModuloNumber<int, 7> mint7;

TEST_CASE("Small number arithmetic") {
    SECTION("addition") {
        mint7 a1 = 12;
        mint7 a2 = 13;

        REQUIRE(a1 + a2 == 4);
        REQUIRE(a1 + a2 != 5);
        REQUIRE(a1 + a2 == 25);
        REQUIRE(a1 + a2 != 26);

        REQUIRE(a1++ == 5);
        REQUIRE(a1 == 6);
        REQUIRE(++a1 == 0);
        REQUIRE(a1 == 0);
    }

    SECTION("subtraction") {
        mint7 a1 = 4;
        mint7 a2 = 17;

        REQUIRE(a1 - a2 == 1);
        REQUIRE(a2 - a1 == 6);

        REQUIRE(a1-- == 4);
        REQUIRE(a1 == 3);
        REQUIRE(--a1 == 2);
        REQUIRE(a1 == 2);
    }

    SECTION("multiplication") {
        mint7 a1 = 12;
        mint7 a2 = 13;

        REQUIRE(a1 * a2 == 2);
    }
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
        REQUIRE(stream.str() == "ModuloNumber(2 mod 7) ModuloNumber(5 mod 7)");
    }
}