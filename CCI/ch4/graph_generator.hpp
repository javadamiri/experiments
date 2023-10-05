#include <iostream>
#include <list>
#include <memory>

namespace {
template <class ConType>
struct myNode {
  using myEdge = myNode<ConType> *;
  ConType content;
  std::list<myEdge> edges;
};
}  // namespace

template <class ConType>
class myGraph {
 private:
  std::list<std::unique_ptr<myNode<ConType>>> nodes;

 public:
  using Node = myNode<ConType>;
  using Edge = myNode<ConType> *;

  myGraph(/* args */);
  ~myGraph();
};
