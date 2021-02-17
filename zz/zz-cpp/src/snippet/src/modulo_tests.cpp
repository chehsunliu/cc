#include <sstream>
#include <string>

#include "catch2/catch.hpp"
#include "snippet/modulo.hpp"

using namespace snippet::modulo;

typedef ModuloNumber<int, 7> mint7;

TEST_CASE("Small number") {
    SECTION("Constructors") {
        REQUIRE(mint7(-8) == 6);
        REQUIRE(mint7(-1) == 6);
        REQUIRE(mint7(6) == 6);
        REQUIRE(mint7(13) == 6);
    }

    SECTION("Comparison operators") {
        REQUIRE(mint7(3) == mint7(10));
        REQUIRE(mint7(3) != mint7(9));
        REQUIRE(mint7(3) > mint7(9));
        REQUIRE(mint7(3) >= mint7(10));
        REQUIRE(mint7(14) < mint7(11));
        REQUIRE(mint7(14) <= mint7(10));
    }

    SECTION("Immutable arithmetic operators") {
        mint7 a1 = 12, a2 = 13;

        REQUIRE(a1 + a2 == 4);
        REQUIRE(a1 + a2 != 5);
        REQUIRE(a1 + a2 == 25);
        REQUIRE(a1 + a2 != 26);

        REQUIRE(a1 - a2 == 6);
        REQUIRE(a2 - a1 == 1);

        REQUIRE(a1 * a2 == 2);
        REQUIRE(a1 * a2 * a1 == 3);
    }

    SECTION("Mutable arithmetic operators / addition") {
        mint7 a1 = 12;
        REQUIRE(a1++ == 5);
        REQUIRE(a1 == 6);
        REQUIRE(++a1 == 0);
        REQUIRE(a1 == 0);

        REQUIRE((a1 += 15) == 1);
        REQUIRE((a1 += 6) == 0);
    }

    SECTION("Mutable arithmetic operators / subtraction") {
        mint7 a1 = 4;
        REQUIRE(a1-- == 4);
        REQUIRE(a1 == 3);
        REQUIRE(--a1 == 2);
        REQUIRE(a1 == 2);
        REQUIRE(--a1 == 1);
        REQUIRE(--a1 == 0);
        REQUIRE(--a1 == 6);

        REQUIRE((a1 -= 15) == 5);
        REQUIRE((a1 -= 6) == 6);
    }

    SECTION("Mutable arithmetic operators / multiplication") {
        mint7 a1 = 4;
        REQUIRE((a1 *= 15) == 4);
        REQUIRE((a1 *= 6) == 3);
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