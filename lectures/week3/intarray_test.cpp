#include <utility>

#include "catch.h"
#include "lectures/week3/intarray.h"

SCENARIO() {
  GIVEN("A simple IntArray") {
    IntArray array{2};

    THEN("The size should be correct") {
      REQUIRE(array.size() == 2);
    }

    AND_THEN("The initial values should be 0") {
      REQUIRE(array.At(0) == 0);
      REQUIRE(array.At(1) == 0);
    }

    WHEN("You modify the value returned by at") {
      array.At(1) = 10;

      THEN("The value persists in the array") {
        REQUIRE(array.At(1) == 10);
      }
    }
  }

  GIVEN("The IntArray {0, 1}") {
    IntArray array{2};
    array.At(1) = 1;

//    WHEN("You attempt to make a const reference to the array") {
//      const auto& cref{array};
//
//      THEN("You can successfully index using the const reference") {
//        REQUIRE(cref.At(0) == 0);
//        REQUIRE(cref.At(1) == 1);
//      }
//    }

    WHEN("You copy-construct the array") {
      auto copy{array};

      THEN("The copy has the same data") {
        REQUIRE(copy.size() == 2);
        REQUIRE(copy.At(0) == 0);
        REQUIRE(copy.At(1) == 1);
      }

      AND_WHEN("You modify the copy") {
        copy.At(0) = 10;

        THEN("The original is not modified") {
          REQUIRE(copy.At(0) == 10);
          REQUIRE(array.At(0) == 0);
        }
      }
    }

    WHEN("You copy-assign the array") {
      // This part requires valgrind or similar.
      IntArray copy{5};
      copy = array;

      THEN("The copy has the same data") {
        REQUIRE(copy.size() == 2);
        REQUIRE(copy.At(0) == 0);
        REQUIRE(copy.At(1) == 1);
      }

      AND_WHEN("You modify the copy") {
        copy.At(0) = 10;

        THEN("The original is not modified") {
          REQUIRE(copy.At(0) == 10);
          REQUIRE(array.At(0) == 0);
        }
      }
    }

    WHEN("You move the array") {
      auto from{array};
      auto moved{std::move(from)};

      THEN("The new array has the same data") {
        REQUIRE(moved.size() == 2);
        REQUIRE(moved.At(0) == 0);
        REQUIRE(moved.At(1) == 1);
      }

      AND_THEN("The original has no data") {
        REQUIRE(from.size() == 0);
      }
    }

    WHEN("You move-assign the array") {
      auto from{array};
      // This part requires valgrind or similar.
      IntArray moved{5};
      moved = std::move(from);

      THEN("The new array has the same data") {
        REQUIRE(moved.size() == 2);
        REQUIRE(moved.At(0) == 0);
        REQUIRE(moved.At(1) == 1);
      }

      AND_THEN("The original has no data") {
        REQUIRE(from.size() == 0);
      }
    }
  }
}
