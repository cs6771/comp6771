#include <iostream>
#include <map>
#include <string>
#include <utility>

int main() {
  std::map<std::string, double> m;
  // The insert function takes in a key-value pair.
  std::pair<std::string, double> p1{"bat", 14.75};
  m.insert(p1);
  // The compiler will automatically construct values as
  // required when it knows the required type.
  m.insert({"cat", 10.157});
  // This is the preferred way of using a map
  m.emplace("cat", 10.157);

  // This is very dangerous, and one of the most common causes of mistakes in C++.
  std::cout << m["bat"] << '\n';

  auto it = m.find("bat");  // Iterator to bat if present, otherwise m.end()

  // This is a great example of when to use auto, but we want to show you what type it is.
  for (const std::pair<const std::string, double>& kv : m) {
    std::cout << kv.first << ' ' << kv.second << '\n';
  }
}
