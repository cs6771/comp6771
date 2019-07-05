// Point.h:
class Point {
 public:
  int& operator[](int i);       // setting via []
  int operator[](int i) const;  // getting via []

 private:
  int x_;
  int y_;
};

// Point.cpp:
#include <cassert>
int& Point::operator[](int i) {
  assert(i == 0 || i == 1);
  if (i == 0)
    return this->x_;
  else
    return this->y_;
}

int Point::operator[](int i) const {
  assert(i == 0 || i == 1);
  if (i == 0)
    return this->x_;
  else
    return this->y_;
}
