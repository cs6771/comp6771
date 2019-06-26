// Point.h:
class Point {
  public:
    // hidden friend - preferred
    friend bool operator==(const Point& p1, const Point& p2) {
      return p1.x_ == p2.x_ && p1.y_ == p2.y_;
      // return std::tie(p1.x_, p1.y_) == std::tie(p2.x_, p2.y_);
    }
    friend bool operator!=(const Point& p1, const Point& p2) {
      return !(p1 == p2);
    }
    friend bool operator<(const Point& p1, const Point& p2) {
      // Do we want this? Alternatives?
    }
    friend bool operator<=(const Point& p1, const Point& p2);
    friend bool operator>(const Point& p1, const Point& p2);
    friend bool operator>=(const Point& p1, const Point& p2);

  private:
    int x_;
    int y_;
};
