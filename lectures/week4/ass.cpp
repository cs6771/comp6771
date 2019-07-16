// Point.h:
#include <istream>
class Point {
 public:
  Point& operator=(const Point& p);
  Point& operator=(std::istream& is);

 private:
  int x_;
  int y_;
};

// Point.cpp:
// #include <istream>
Point& Point::operator=(const Point& p) {
  this->x_ = p.x_;
  this->y_ = p.y_;
  return *this;
}
Point& Point::operator=(std::istream& is) {
  // etc
}
