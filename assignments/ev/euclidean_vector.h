// TODO(you): Include header guards

#include <exception>
#include <string>
#include <memory>

class EuclideanVectorError : public std::exception {
 public:
  explicit EuclideanVectorError(const std::string& what) : what_(what) {}
  const char* what() const noexcept{ return what_.c_str(); }
 private:
  std::string what_;
};

class EuclideanVector {
 public:
  explicit EuclideanVector(int i);
  friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);
  // TODO(you): add more
 private:
  std::unique_ptr<double[]> magnitudes_;
  // TODO(you): add more
};
