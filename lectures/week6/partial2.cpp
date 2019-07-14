#include <exception>
#include <memory>

class MyInt {
 public:
  explicit MyInt(int i) : i_{i} {
    if (i == 2)
      throw std::exception();
  }

 private:
  int i_;
};

class UnsafeClass {
 public:
  UnsafeClass(int a, int b) : a_{std::make_unique<MyInt>(a)}, b_{std::make_unique<MyInt>(b)} {}

 private:
  std::unique_ptr<MyInt> a_;
  std::unique_ptr<MyInt> b_;
};

int main() {
  UnsafeClass a{1, 2};
}
