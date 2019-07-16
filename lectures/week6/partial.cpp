#include <exception>

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
  UnsafeClass(int a, int b) : a_{new MyInt{a}}, b_{new MyInt{b}} {}

  ~UnsafeClass() {
    delete a_;
    delete b_;
  }

 private:
  MyInt* a_;
  MyInt* b_;
};

int main() {
  UnsafeClass a{1, 2};
}
