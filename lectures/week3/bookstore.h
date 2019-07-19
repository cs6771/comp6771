#ifndef LECTURES_WEEK3_BOOKSTORE_H_
#define LECTURES_WEEK3_BOOKSTORE_H_

#include <iostream>
#include <optional>
#include <string>

class BookSale {
 public:
  // constructors
  explicit BookSale(const std::string& name) : BookSale{name, 0, 0.0} {}
  BookSale(const std::string& name, int n_sold, double price)
    : book_name_{name}, units_sold_{n_sold}, price_{price} {
    ++counter;
  }
  BookSale() : BookSale{""} {}
  explicit BookSale(std::istream&);

  // operations on BookSale objects
  const std::string& getBookName();
  BookSale& combine(const BookSale&);
  double revenue() const;

 private:
  std::string book_name_;
  int units_sold_ = 0;  // in-class initialiser.
  double price_ = 0;    // in-class initialiser.
  mutable std::optional<double> revenueCache_;

  // Count how many objs are created by this constructor
  static int counter;

  friend std::istream& read(std::istream& is, BookSale& item);
  friend std::ostream& print(std::ostream&, BookSale&);
};

std::istream& read(std::istream& is, BookSale& item);
std::ostream& print(std::ostream&, const BookSale&);

BookSale add(const BookSale&, const BookSale&);

#endif  // LECTURES_WEEK3_BOOKSTORE_H_
