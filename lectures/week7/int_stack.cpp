#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

using std::begin;
using std::cbegin;
using std::end;

class IntStack {
 private:
  struct Node {
    Node(int value, std::unique_ptr<Node>&& next): value{value}, next{std::move(next)} {}
    int value;
    std::unique_ptr<Node> next;
  };

  // Exercise to the reader once we've covered templates:
  // Try making the const iterator and the non-const iterator with one class template.
  class Iterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using reference = int&;
    using pointer = int*;
    using difference_type = int;

    reference operator*() const { return node_->value; }
    pointer operator->() const { return &(operator*()); }
    Iterator operator++() {
      node_ = node_->next.get();
      return *this;
    }
    Iterator operator++(int) {
      auto copy{*this};
      ++(*this);
      return copy;
    }

    friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
      return lhs.node_ == rhs.node_;
    }

    friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

   private:
    explicit Iterator(Node* node): node_{node} {}
    Node* node_;

    friend class IntStack;
  };

 public:
  // TODO(lecture): show how make const and non-const iterators during lecture.
  using iterator = Iterator;
  using const_iterator = Iterator;

  iterator begin() { return iterator{head_.get()}; }
  const_iterator begin() const { return cbegin(); }
  const_iterator cbegin() const { return const_iterator{head_.get()}; }
  iterator end() { return iterator{nullptr}; }
  const_iterator end() const { return cend(); }
  const_iterator cend() const { return const_iterator{nullptr}; }

  void push(int value) { head_ = std::make_unique<Node>(value, std::move(head_)); }

  // TODO(students): Why doesn't std::stack::pop return the value you pop?
  void pop() { head_ = std::move(head_->next); }

  const int& top() const { return *cbegin(); }
  int& top() { return *begin(); }

 private:
  std::unique_ptr<Node> head_;
};

int main() {
  IntStack l;
  l.push(5);
  l.push(4);
  l.push(3);
  l.push(2);
  l.push(1);

  std::cout << std::boolalpha;
  std::cout << "Head is " << l.top() << '\n';
  l.pop();
  std::cout << "After popping, head is " << l.top() << '\n';

  std::cout << "Algorithms\n";
  std::copy(begin(l), end(l), std::ostream_iterator<int>{std::cout, "\n"});

  auto check_present = [&] (int value) {
    std::cout << "Is " << value << " present: "
              << (std::find(begin(l), end(l), 5) != end(l)) << '\n';
  };
  check_present(5);
  check_present(99);
  (*begin(l)) = 99;
  check_present(99);

  // TODO(lecture): This should fail to compile
  (*cbegin(l)) = 100;

  std::cout << "Range-for\n";
  for (const auto& item : l) {
    std::cout << item << '\n';
  }
}
