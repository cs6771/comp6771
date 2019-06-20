#include "catch.h"
#include "tutorials/week3/dictionary_library.h"

// TODO(tutorial): Discuss why we write this function here, and why we shouldn't just have it in our
//  program.
std::string GetValidWords(const std::vector<std::string>& words, const std::string& value) {
  std::istringstream is{value};
  std::ostringstream out;
  PrintValidWords(words, is, out);
  return out.str();
}

// TODO(tutorial): Discuss what should be tested, and what shouldn't be tested. Discuss how much
// testing is enough, and discuss the value of each different require that you add.
TEST_CASE("Empty word list means nothing is valid") {
  REQUIRE(GetValidWords({}, "").empty());
  REQUIRE(GetValidWords({}, "hello").empty());
  REQUIRE(GetValidWords({}, "hello world").empty());
}

TEST_CASE("One word means only that word is valid") {
  REQUIRE(GetValidWords({"hello"}, "").empty());
  // TODO(tutorial): Add more tests here
}

TEST_CASE("Multiple words means they are all valid") {
  REQUIRE(GetValidWords({"hello", "world"}, "").empty());
  // TODO(tutorial): Add more tests here
}
