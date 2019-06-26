#include <iostream>
class StringPtr {
  public:
    StringPtr(std::string *p) : ptr{p} { }
    ~StringPtr() { delete ptr; }
    std::string* operator->() { return ptr; }
    std::string& operator*() { return *ptr; }
  private:
    std::string *ptr;
};

int main() {
  std::string *ps = new std::string{"smart pointer"};
  StringPtr p{ps};
  std::cout << *p << std::endl;
  std::cout << p->size() << std::endl;
}
