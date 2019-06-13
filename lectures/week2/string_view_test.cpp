#include "catch.h"
#include "lectures/week2/string_view.h"

// Function definitions can have auto return types in C++17
auto EqualsString([[maybe_unused]] const std::vector<std::string>& strings) {
  return Catch::Predicate<RopeView>([] ([[maybe_unused]] const RopeView expected) {
    return true;
  });
}

SCENARIO() {
  WHEN("You try to split an empty string") {
    std::string emptyString;
    const RopeView& result = Split(emptyString, ' ');
    THEN("You get a single empty result") {
      CHECK(result.size() == 1);
      REQUIRE(std::distance(result[0].first, result[0].second) == 0);
      // Alternatively, we can use predicates.
      REQUIRE_THAT(result, EqualsString({""}));
    }
  }
}

SCENARIO("Do that thing with the thing", "[Tags]") {
  GIVEN("This stuff exists") {
    // make stuff exist
    AND_GIVEN("And some assumption") {
      // Validate assumption
      WHEN("I do this") {
        // do this
        THEN("it should do this") {
          // REQUIRE(itDoesThis());
          AND_THEN("do that") {
            // REQUIRE(itDoesThat());
          }
        }
      }
    }
  }
}
