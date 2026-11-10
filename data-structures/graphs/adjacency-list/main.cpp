#include "AdjacencyList.hpp"

int main() {
  /*
  AdjacencyList<int, int> asd(NOT_DIRECTED, NOT_WEIGHTED);

  asd.addVertex(23);

  asd.addVertex(32);

  asd.addVertex(0);
  asd.addVertex(1);
  asd.addVertex(2);

  asd.addEdge(32, 23, 2);

  asd.addEdge(0, 1);
  asd.addEdge(0, 2);
  asd.addEdge(1, 2);
  asd.addEdge(2, 32);

  asd.printGraph();

  asd.removeVertex(1);

  asd.printGraph();

  AdjacencyList<int, int> asd(DIRECTED, WEIGHTED);

  asdd.addVertex(23);

  asdd.addVertex(32);

  asdd.addVertex(0);
  asdd.addVertex(1);
  asdd.addVertex(2);

  asdd.addEdge(32, 23, 2);

  asdd.addEdge(0, 1, 5);
  asdd.addEdge(0, 2);
  asdd.addEdge(1, 2, 123);
  asdd.addEdge(2, 32);

  asdd.printGraph();
  */

  AdjacencyList<int, int> asd(NOT_DIRECTED, NOT_WEIGHTED);
  int exmpl1 = 1;
  int exmpl2 = 2;

  asd.addVertex(0);
  asd.addVertex(exmpl1);
  asd.addVertex(exmpl2);

  int test1 = 3;

  // std::cout << (asd.hasVertex(exmpl1) ? "has " : "doesn't have ") << "vertex " << exmpl1 << std::endl;
  // std::cout << (asd.hasVertex(test1) ? "has " : "doesn't have ") << "vertex " << test1 << std::endl;

  asd.addEdge(0, 1, 5);
  //asd.addEdge(0, 2);
  //asd.addEdge(2, 0);
  //asd.addEdge(2, 0);
  //asd.addEdge(2, 0);
  asd.addEdge(2, 1);
  asd.addEdge(1, 0);
  asd.addEdge(1, 2);

  asd.printGraph();

  std::cout << asd.getOutDegree(0) << std::endl;
  std::cout << asd.getOutDegree(1) << std::endl;
  std::cout << asd.getOutDegree(2) << std::endl;

  std::cout << exmpl1 << " " << (asd.hasEdge(exmpl1, exmpl2) ? "has " : "doesn't have ")  << " " << exmpl2 << std::endl;
  std::cout << exmpl2 << " " << (asd.hasEdge(exmpl2, exmpl1) ? "has " : "doesn't have ")  << " " << exmpl1 << std::endl;
  std::cout << exmpl1 << " " << (asd.hasEdge(exmpl1, 0) ? "has " : "doesn't have ")  << " 0" << std::endl;


  for (const auto &a: asd.getAdjacentVertices(1)) {
    std::cout << a << std::endl;
  }


  //asd.removeVertex(0);

  //asd.printGraph();
}