#include <iostream>
#include <string>

#include "lectures/week3/bookstore.h"

BookSale::BookSale(std::istream& is) {
  read(is, *this);
}

const std::string& BookSale::getBookName() {
  return book_name_;
}

double BookSale::revenue() const {
  if (!revenueCache_) {
    revenueCache_ = units_sold_ * price_;
  }
  return *revenueCache_;
}

BookSale& BookSale::combine(const BookSale& rhs) {
  units_sold_ += rhs.units_sold_;
  revenueCache_.reset();
  return *this;
}

std::istream& read(std::istream& is, BookSale& item) {
  is >> item.book_name_ >> item.units_sold_ >> item.price_;
  return is;
}

std::ostream& print(std::ostream& os, BookSale& item) {
  os << item.units_sold_ << "*" << item.book_name_ << "@$" << item.price_ << " = $"
     << item.revenue();
  return os;
}

BookSale add(const BookSale& lhs, const BookSale& rhs) {
  BookSale sum = lhs;
  sum.combine(rhs);
  return sum;  // must not return it by ref/ptr
}  // look at moving semantics

// init the static member
int BookSale::counter = 0;
