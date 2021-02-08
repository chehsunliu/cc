#include <vector>

#include "catch2/catch.hpp"

#include "snippet/prime.hpp"

TEST_CASE("prime generation") {
    SECTION("smallest prime") {
        int upperBound = 2;
        std::vector<int> primes = snippet::prime::createPrimes(upperBound);
        std::vector<int> expected({2});
        REQUIRE(primes == expected);

        std::set<int> primeSet = snippet::prime::createPrimeSet(upperBound);
        REQUIRE(primeSet == std::set<int>(expected.begin(), expected.end()));
    }

    SECTION("no prime") {
        int upperBound = 1;
        std::vector<int> primes = snippet::prime::createPrimes(upperBound);
        std::vector<int> expected;
        REQUIRE(primes == expected);

        std::set<int> primeSet = snippet::prime::createPrimeSet(upperBound);
        REQUIRE(primeSet == std::set<int>(expected.begin(), expected.end()));
    }

    SECTION("upperBound is not prime") {
        int upperBound = 14;
        std::vector<int> primes = snippet::prime::createPrimes(upperBound);
        std::vector<int> expected({2, 3, 5, 7, 11, 13});
        REQUIRE(primes == expected);

        std::set<int> primeSet = snippet::prime::createPrimeSet(upperBound);
        REQUIRE(primeSet == std::set<int>(expected.begin(), expected.end()));
    }

    SECTION("upperBound is prime") {
        int upperBound = 11;
        std::vector<int> primes = snippet::prime::createPrimes(upperBound);
        std::vector<int> expected({2, 3, 5, 7, 11});
        REQUIRE(primes == expected);

        std::set<int> primeSet = snippet::prime::createPrimeSet(upperBound);
        REQUIRE(primeSet == std::set<int>(expected.begin(), expected.end()));
    }
}
