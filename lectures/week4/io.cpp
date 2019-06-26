// Point.h:
#include <ostream>
#include <istream>
class Point {
  public:
    Point(int x, int y) : x_{x}, y_{y} {};
    friend std::ostream& operator<<(std::ostream& os, const Point& type); 
    friend std::istream& operator>>(std::istream& is, Point& type); 

  private:
    int x_;
    int y_;
};

// Point.cpp:
#include <ostream>
#include <istream>
#include <iostream>
std::ostream& operator<<(std::ostream& os, const Point& p) {
  os << "(" << p.x_ << "," << p.y_ << ")";
  return os;
}
std::istream& operator>>(std::istream& is, Point& type) {
  // To be done in tutorials
}

int main() {
  Point p{1,2};
  std::cout << p << '\n';
}
