#include <sstream>
#include <string>

#include "catch2/catch.hpp"
#include "codebook/modulo.hpp"

using namespace codebook::modulo;

typedef ModuloInt<7> mint7;
typedef ModuloInt<1000000007> mint;

TEST_CASE("Modulo 7") {
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
        REQUIRE(a1 * a2 * a1 * 0 == 0);

        REQUIRE(a1 / a2 == 2);
        REQUIRE(a2 / a1 == 4);
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

    SECTION("Mutable arithmetic operators / division") {
        REQUIRE((mint7(5) /= 1) == 5);
        REQUIRE((mint7(5) /= 2) == 6);
        REQUIRE((mint7(5) /= 3) == 4);
        REQUIRE((mint7(5) /= 4) == 3);
        REQUIRE((mint7(5) /= 5) == 1);
        REQUIRE((mint7(5) /= 6) == 2);
        REQUIRE((mint7(5) /= 7) == 0);
    }

    SECTION("Power") {
        mint7 a = 2;
        REQUIRE(a.power(0) == 1);
        REQUIRE(a.power(1) == 2);
        REQUIRE(a.power(2) == 4);
        REQUIRE(a.power(3) == 1);
        REQUIRE(a.power(4) == 2);

        a = 3;
        REQUIRE(a.power(0) == 1);
        REQUIRE(a.power(1) == 3);
        REQUIRE(a.power(2) == 2);
        REQUIRE(a.power(3) == 6);
        REQUIRE(a.power(4) == 4);
        REQUIRE(a.power(5) == 5);
        REQUIRE(a.power(6) == 1);

        a = 12;
        REQUIRE(a.power(0) == 1);
        REQUIRE(a.power(1) == 5);
        REQUIRE(a.power(2) == 4);
        REQUIRE(a.power(3) == 6);
        REQUIRE(a.power(4) == 2);
        REQUIRE(a.power(5) == 3);
        REQUIRE(a.power(6) == 1);
    }
}

TEST_CASE("Modulo 1000000007") {
    SECTION("Inverse") {
        REQUIRE(mint(123).inverse() == 886178868);
        REQUIRE(mint(555).inverse() == 174774776);
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
        REQUIRE(stream.str() == "2 5");
    }
}