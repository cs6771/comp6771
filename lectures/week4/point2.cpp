#include <iostream>
#include <ostream>

class Point {
 public:
  Point(int x, int y) : x_{x}, y_{y} {};
  friend Point operator+(const Point& lhs, const Point& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Point& p);

 private:
  int x_;
  int y_;
};

Point operator+(const Point& lhs, const Point& rhs) {
  return Point{lhs.x_ + rhs.x_, lhs.y_ + rhs.y_};
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.x_ << "," << p.y_ << ")";
  return os;
}

int main() {
  Point p1{1, 2};
  Point p2{2, 3};
  std::cout << p1 + p2 << "\n";
}
