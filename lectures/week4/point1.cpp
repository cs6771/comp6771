#include <iostream>
#include <ostream>

class Point {
 public:
  Point(int x, int y) : x_{x}, y_{y} {};
  const int& x() const { return this->x_; }
  const int& y() const { return this->y_; }
  static Point add(const Point& p1, const Point& p2);

 private:
  int x_;
  int y_;
};

void print(std::ostream& os, const Point& p) {
  os << "(" << p.x() << "," << p.y() << ")";
}

Point Point::add(const Point& p1, const Point& p2) {
  return Point{p1.x() + p2.x(), p1.y() + p2.y()};
}

int main() {
  Point p1{1, 2};
  Point p2{2, 3};
  print(std::cout, Point::add(p1, p2));
  std::cout << "\n";
}
