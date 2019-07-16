#include <iostream>

class EV {
 public:
  explicit EV(int i = 1) : i_{i} {}
  int get() const { return i_; }
 private:
  int i_;
};

int main() {
  EV a{2};
  EV b{};
  EV c = EV({});
  EV d = EV(3);
  std::cout << c.get() << "\n";
  std::cout << d.get() << "\n";
}
