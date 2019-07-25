#ifndef LECTURES_WEEK8_FORWARDING_TYPES_H_
#define LECTURES_WEEK8_FORWARDING_TYPES_H_

#include <iostream>
#include <string>

class MyClass: public std::string {
 public:
  // Steal std::string constructors. This gives us MyClass(const char*), for example.
  using std::string::string;

  MyClass(const MyClass& old): std::string{old} {
    std::cout << "Copying " << old << '\n';
  }
  MyClass(MyClass&& old) noexcept: std::string{std::move(old)} {
    std::cout << "Moving " << *this << '\n';
  }
  MyClass& operator=(const MyClass&) = default;
  MyClass& operator=(MyClass&&) noexcept = default;
};

class NonCopyable: public MyClass {
 public:
  using MyClass::MyClass;
  NonCopyable(const NonCopyable&) = delete;
  NonCopyable(NonCopyable&&) noexcept = default;
  NonCopyable& operator=(const NonCopyable&) = delete;
  NonCopyable& operator=(NonCopyable&&) noexcept = default;
};


#endif  // LECTURES_WEEK8_FORWARDING_TYPES_H_
