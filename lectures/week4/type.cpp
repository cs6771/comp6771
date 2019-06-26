// Point.h:
#include <vector>
class Point {
  public:
    Point(int x, int y) : x_(x), y_(y) {}
    operator std::vector<int>() {
      std::vector<int> vec;
      vec.push_back(x_);
      vec.push_back(y_);
      return vec;
    }

  private:
    int x_;
    int y_;
};

// Point.cpp:
#include <iostream>
#include <vector>
int main() {
  Point p{1,2};
  std::vector<int> vec = static_cast<std::vector<int>>(p);
  std::cout << vec[0] << '\n';
  std::cout << vec[1] << '\n';
}
