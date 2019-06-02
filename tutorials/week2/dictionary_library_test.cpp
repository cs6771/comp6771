#include "catch.h"
#include "tutorials/week2/dictionary_library.h"

std::string get_valid_words(const std::vector<std::string>& words, const std::string& value) {
  std::istringstream is{value};
  std::ostringstream out;
  print_valid_words(words, is, out);
  return out.str();
}

TEST_CASE("Empty word list means nothing is valid") {
  REQUIRE(get_valid_words({}, "").empty());
  REQUIRE(get_valid_words({}, "hello").empty());
  REQUIRE(get_valid_words({}, "hello world").empty());
}

TEST_CASE("One word means only that word is valid") {
  REQUIRE(get_valid_words({"hello"}, "").empty());
  REQUIRE(get_valid_words({"hello"}, "hello") == "hello ");
  REQUIRE(get_valid_words({"hello"}, "invalid").empty());
  REQUIRE(get_valid_words({"hello"}, "hello hello") == "hello hello ");
  REQUIRE(get_valid_words({"hello"}, "hello world") == "hello ");
}

TEST_CASE("Multiple words means they are all valid") {
  REQUIRE(get_valid_words({"hello", "world"}, "").empty());
  REQUIRE(get_valid_words({"hello", "world"}, "hello") == "hello ");
  REQUIRE(get_valid_words({"hello", "world"}, "invalid").empty());
  REQUIRE(get_valid_words({"hello", "world"}, "hello hello") == "hello hello ");
  REQUIRE(get_valid_words({"hello", "world"}, "hello world") == "hello world ");
}
