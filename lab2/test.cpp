#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PrimeNumbersGenerator.hpp"

SCENARIO("Set of prime numbers up to 4")
{
    REQUIRE(GeneratePrimeNumbersSet(4) == std::set<int>{2, 3});
}

SCENARIO("Set of prime numbers up to 0")
{
    REQUIRE(GeneratePrimeNumbersSet(0) == std::set<int>{});
}

SCENARIO("Set of prime numbers up to 1")
{
    REQUIRE(GeneratePrimeNumbersSet(1) == std::set<int>{});
}

SCENARIO("Count of prime numbers up to 1000")
{
    REQUIRE(GeneratePrimeNumbersSet(1000).size() == 168);
}

SCENARIO("Count of prime numbers up to 1e8")
{
    REQUIRE(GeneratePrimeNumbersSet(100000000).size() == 5761455);
}
