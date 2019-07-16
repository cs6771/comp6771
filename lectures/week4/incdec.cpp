// RoadPosition.h:
class RoadPosition {
 public:
  explicit RoadPosition(int km) : km_from_sydney_(km) {}
  RoadPosition& operator++();  // prefix
  // This is *always* an int, no
  // matter your type.
  RoadPosition operator++(int);  // postfix
  void tick();
  int km() { return km_from_sydney_; }

 private:
  void tick_();
  int km_from_sydney_;
};

// RoadPosition.cpp:
#include <iostream>
RoadPosition& RoadPosition::operator++() {
  this->tick_();
  return *this;
}
RoadPosition RoadPosition::operator++(int) {
  RoadPosition rp = *this;
  this->tick_();
  return rp;
}
void RoadPosition::tick_() {
  ++(this->km_from_sydney_);
}

int main() {
  RoadPosition rp{5};
  std::cout << rp.km() << '\n';
  int val1 = (rp++).km();
  int val2 = (++rp).km();
  std::cout << val1 << '\n';
  std::cout << val2 << '\n';
}
