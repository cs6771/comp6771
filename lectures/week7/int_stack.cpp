#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <utility>

using std::begin;
using std::cbegin;
using std::end;
using std::rbegin;
using std::rend;

class IntList {
 private:
  struct Node {
    Node(int value, std::unique_ptr<Node>&& next, Node* prev): value{value}, next{std::move(next)}, prev{prev} {}
    int value;
    std::unique_ptr<Node> next;
    Node* prev;
  };

  // Exercise to the reader once we've covered templates:
  // Try making the const iterator and the non-const iterator with one class template.
  template <typename T>
  class Iterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using reference = T&;
    using pointer = T*;
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
    Iterator operator--() {
      node_ = node_->prev;
      return *this;
    }
    Iterator operator--(int) {
      auto copy{*this};
      --(*this);
      return copy;
    }


    friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
      return lhs.node_ == rhs.node_;
    }

    friend bool operator!=(const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

   private:
    explicit Iterator(Node* node): node_{node} {}
    Node* node_;

    // For the constructor.
    friend class IntList;
  };

 public:
  IntList() : head_(std::make_unique<Node>(0, nullptr, nullptr)), tail_{head_.get()} {}
  // Note: you normally wouldn't want to iterate through stacks.
  // TODO(lecture): show how make const and non-const iterators during lecture.
  using iterator = Iterator<int>;
  using const_iterator = Iterator<const int>;

  iterator begin() { return iterator{head_.get()}; }
  const_iterator begin() const { return cbegin(); }
  const_iterator cbegin() const { return const_iterator{head_.get()}; }
  iterator end() { return iterator{tail_}; }
  const_iterator end() const { return cend(); }
  const_iterator cend() const { return const_iterator{tail_}; }


  // Make the iterator using these.
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  // Need to define these.
  reverse_iterator rbegin() { return reverse_iterator{end()}; }
  reverse_iterator rend() { return reverse_iterator{begin()}; }

  // If you want const reverse iterators (hint: you do), define these.
  const_reverse_iterator rbegin() const { return crbegin(); }
  const_reverse_iterator rend() const { return crend(); }
  const_reverse_iterator crbegin() const { return const_reverse_iterator{cend()}; }
  const_reverse_iterator crend() const { return const_reverse_iterator{cbegin()}; }

  void push(int value) {
    head_ = std::make_unique<Node>(value, std::move(head_), nullptr);
    head_->next->prev = head_.get();
  }

  // TODO(students): Why doesn't std::stack::pop return the value you pop?
  void pop() { head_ = std::move(head_->next); }

  const int& top() const { return *cbegin(); }
  int& top() { return *begin(); }

 private:
  std::unique_ptr<Node> head_;
  Node* tail_;
};

int main() {
  IntList l;
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
  std::copy(rbegin(l), rend(l), std::ostream_iterator<int>{std::cout, "\n"});

  auto check_present = [&] (int value) {
    std::cout << "Is " << value << " present: "
              << (std::find(begin(l), end(l), value) != end(l)) << '\n';
  };
  check_present(5);
  check_present(99);
  (*begin(l)) = 99;
  check_present(99);

  // TODO(lecture): This should fail to compile
//  (*cbegin(l)) = 100;

  std::cout << "Range-for\n";
  for (const auto& item : l) {
    std::cout << item << '\n';
  }
}
