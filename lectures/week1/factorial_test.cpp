#include "catch.h"
#include "lectures/week1/factorial.h"

TEST_CASE("2: Factorial of 0 is 1") {
  REQUIRE(Factorial(0) == 1);
}

TEST_CASE("2: Factorials of 1 and higher are computed") {
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
}
