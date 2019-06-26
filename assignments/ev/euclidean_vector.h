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
  EuclideanVector CreateUnitVector() {
  	if (this->GetNumDimensions() == 0) {
  		throw EuclideanVectorError("EuclideanVector with no dimensions does not have a unit vector");
  	}
  	// do ma stuff
  }
  double testHi() {
  	return this->magnitudes_[0];
  }
  // TODO(you): add more
 private:
  std::unique_ptr<double[]> magnitudes_;
  // TODO(you): add more
};
