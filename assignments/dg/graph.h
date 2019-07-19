#ifndef ASSIGNMENTS_DG_GRAPH_H_
#define ASSIGNMENTS_DG_GRAPH_H_

#include <memory>

namespace gdwg {

template<typename T>
// requires Relation<Less<T>, T>()
struct CompareByValue {
  bool operator()(const std::smart_ptr<T>& lhs, const std::smart_ptr<T>& rhs) const {
    return *lhs < *rhs;
  }
};

template<typename N, typename E>
class Graph {
 public:
 private:
  std::set<std::smart_ptr<Node>, CompareByValue<Node>> nodes_;
  std::map<std::smart_ptr<Node>, ???, CompareByValue<Node>> nodes_;
};

// Define your graph_iterator here
// Define your graph_const_iterator here

}

#include "assignments/dg/graph.tpp"

#endif  // ASSIGNMENTS_DG_GRAPH_H_
