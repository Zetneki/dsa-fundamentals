#include <iostream>
#include "AdjacencyList.hpp"

int main() {
  AdjacencyList<int, int> asd(false, false);

  asd.addVertex(23);

  asd.addVertex(32);

  asd.removeVertex(2);

  asd.removeVertex(32);
}