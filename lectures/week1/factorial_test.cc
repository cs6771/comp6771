#include "catch2.hpp"
#include "lectures/week1/factorial_lib.h"

TEST_CASE("2: Factorial of 0 is 1 (fail)") {
  REQUIRE(factorial(0) == 1 );
}

TEST_CASE("2: Factorials of 1 and higher are computed (pass)") {
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(3) == 6);
  REQUIRE(factorial(10) == 3628800);
}
