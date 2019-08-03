#include <iostream>

template <typename T>
T min(T a, T b) {
  return a < b ? a : b;
}

double myMin(double a, double b) {
  return a < b ? a : b;
}

int main() {
  int i; double d;
  i = 4;
  d = 5.6;
  //min(i, static_cast<int>(d)); // int min(int, int)
  std::cout << min<int>(i, d) << "\n"; // int min(int, int)
  //min(static_cast<double>(i), d); // double min(double, double)
  //min<double>(i, d); // double min(double, double)
}