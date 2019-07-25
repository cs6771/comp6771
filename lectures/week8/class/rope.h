#ifndef TUTORIALS_WEEK8_ROPE_H_
#define TUTORIALS_WEEK8_ROPE_H_

#include <optional>
#include <string>
#include <utility>
#include <vector>

class Rope {
 public:
  explicit Rope(std::vector<std::string> rope): rope_{std::move(rope)} {}

  class iterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = char;
    using reference = char&;
    using pointer = char*;
    using difference_type = int;

    reference operator*() const;
    iterator& operator++();
    iterator operator++(int) {
      auto copy{*this};
      ++(*this);
      return copy;
    }

    // This one isn't strictly required, but it's nice to have.
    pointer operator->() const { return &(operator*()); }

    friend bool operator==(const iterator& lhs, const iterator& rhs) {
      // We need to check the sentinel because comparison of default constructed iterators is undefined.
      return lhs.outer_ == rhs.outer_ && (lhs.outer_ == lhs.sentinel_ || lhs.inner_ == rhs.inner_);
    }

    friend bool operator!=(const iterator& lhs, const iterator& rhs) { return !(lhs == rhs); }


   private:
    std::vector<std::string>::iterator outer_;
    const std::vector<std::string>::iterator sentinel_;
    std::string::iterator inner_;

    friend class Rope;
    iterator(const decltype(outer_)& outer, const decltype(sentinel_)& sentinel, const decltype(inner_)& inner): outer_{outer}, sentinel_{sentinel}, inner_{inner} {}
  };

  iterator begin();
  iterator end();

 private:
  std::vector<std::string> rope_;
};


#endif  // TUTORIALS_WEEK8_ROPE_H_  