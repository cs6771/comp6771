// Note: At the moment, there is no client.sampleout. Please do your own testing

#include <string>

#include "assignments/dg/graph.h"

int main() {
  gdwg::Graph<std::string, int> g;
  g.InsertNode("hello");
  g.InsertNode("how");
  g.InsertNode("are");
  g.InsertNode("you?");

  g.InsertEdge("hello", "how", 5);
  g.InsertEdge("hello", "are", 8);
  g.InsertEdge("hello", "are", 2);

  g.InsertEdge("how", "you?", 1);
  g.InsertEdge("how", "hello", 4);

  g.InsertEdge("are", "you?", 3);

  std::cout << g << std::endl;

  gdwg::Graph<std::string, int> g2 = g;
  
  std::cout << g2 << "\n";
}
