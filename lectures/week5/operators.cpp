#include <cassert>
#include <iostream>

class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) {}
  int& operator[](int i) {
    assert(i == 0 || i == 1);
    if (i == 0)
      return this->x_;
    else
      return this->y_;
  }

  const int& operator[](int i) const {
    assert(i == 0 || i == 1);
    if (i == 0)
      return this->x_;
    else
      return this->y_;
  }

 private:
  int x_;
  int y_;
};

int main() {
  Point q{99, -5};
  q[0] = -99;
  std::cout << q[0] << "\n";

  const Point p{99, -5};
  std::cout << (p[0] + 1) << "\n";

  int* i = new int{5};
  std::cout << *i << '\n';
}
