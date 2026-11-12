#include "AdjacencyList.hpp"
#include <cassert>
#include <sstream>
#include <string>

// returns true if f throws std::invalid_argument
template <typename F>
bool throwsInvalidArgument(F f) {
  try { f(); }
  catch (const std::invalid_argument &) { return true; }
  return false;
}

// tests: empty graph, added/missing vertices, new vertex has no edges,
// duplicate-free output in insertion order (printGraph)
void testAddVertex() {
  AdjacencyList<std::string> graph(NOT_DIRECTED, NOT_WEIGHTED);

  assert(!graph.hasVertex("Serbia"));

  graph.addVertex("Serbia");
  graph.addVertex("Budapest");
  graph.addVertex("Romania");

  assert(graph.hasVertex("Serbia"));
  assert(graph.hasVertex("Budapest"));
  assert(graph.hasVertex("Romania"));
  assert(!graph.hasVertex("Hungary"));
  assert(graph.getOutDegree("Budapest") == 0);
  assert(graph.getAdjacentVertices("Serbia").empty());

  std::ostringstream out;

  graph.printGraph(out);
  assert(out.str() ==
    "Undirected Graph Adjacency List:\n"
    "Serbia: -> NULL\n"
    "Budapest: -> NULL\n"
    "Romania: -> NULL\n");

  out.str("");

  graph.addVertex("Serbia");

  graph.printGraph(out);
  assert(out.str() ==
    "Undirected Graph Adjacency List:\n"
    "Serbia: -> NULL\n"
    "Budapest: -> NULL\n"
    "Romania: -> NULL\n");
}

// tests: undirected (both directions) vs directed (one direction), weight ignored
// when unweighted, duplicate edge ignored (first weight kept), loop edge and
// missing vertex exceptions
void testAddEdge() {
  AdjacencyList<std::string> unDirectedGraph(NOT_DIRECTED, NOT_WEIGHTED);
  AdjacencyList<std::string> directedGraph(DIRECTED, WEIGHTED);

  unDirectedGraph.addVertex("A");
  unDirectedGraph.addVertex("B");

  directedGraph.addVertex("A");
  directedGraph.addVertex("B");

  unDirectedGraph.addEdge("A", "B", 20);

  directedGraph.addEdge("A", "B", 10);

  assert(unDirectedGraph.hasEdge("A", "B"));
  assert(unDirectedGraph.hasEdge("B", "A"));

  assert(directedGraph.hasEdge("A", "B"));
  assert(!directedGraph.hasEdge("B", "A"));

  unDirectedGraph.addEdge("A", "B");

  assert(unDirectedGraph.getOutDegree("A") == 1);

  assert(throwsInvalidArgument([&] {
    unDirectedGraph.addEdge("A", "A");
  }));
  assert(throwsInvalidArgument([&] {
    unDirectedGraph.addEdge("C", "D");
  }));

  std::ostringstream out;

  unDirectedGraph.printGraph(out);
  assert(out.str() ==
    "Undirected Graph Adjacency List:\n"
    "A: -> B -> NULL\n"
    "B: -> A -> NULL\n");

  out.str("");

  directedGraph.addEdge("A", "B", 99);

  directedGraph.printGraph(out);
  assert(out.str() ==
    "Directed Graph Adjacency List:\n"
    "A: -(10)-> B -> NULL\n"
    "B: -> NULL\n");
}

// tests: removing a vertex also removes edges pointing to it, other vertices
// stay untouched, missing vertex exception
void testRemoveVertex() {
  AdjacencyList<double> graph(NOT_DIRECTED, NOT_WEIGHTED);

  graph.addVertex(1.1);
  graph.addVertex(1.2);
  graph.addVertex(1.3);
  graph.addVertex(1.4);
  graph.addVertex(1.5);

  graph.addEdge(1.1, 1.2);
  graph.addEdge(1.1, 1.3);
  graph.addEdge(1.2, 1.4);
  graph.addEdge(1.3, 1.4);

  std::ostringstream out;

  graph.printGraph(out);
  assert(out.str() ==
    "Undirected Graph Adjacency List:\n"
    "1.1: -> 1.2 -> 1.3 -> NULL\n"
    "1.2: -> 1.1 -> 1.4 -> NULL\n"
    "1.3: -> 1.1 -> 1.4 -> NULL\n"
    "1.4: -> 1.2 -> 1.3 -> NULL\n"
    "1.5: -> NULL\n");

  assert(graph.hasVertex(1.4));
  graph.removeVertex(1.4);
  assert(!graph.hasVertex(1.4));

  out.str("");

  graph.printGraph(out);
  assert(out.str() ==
    "Undirected Graph Adjacency List:\n"
    "1.1: -> 1.2 -> 1.3 -> NULL\n"
    "1.2: -> 1.1 -> NULL\n"
    "1.3: -> 1.1 -> NULL\n"
    "1.5: -> NULL\n");

  assert(throwsInvalidArgument([&] {
    graph.removeVertex(1.6);
  }));
}

// tests: undirected removal on both sides, directed removal only in the given
// direction, removing a non-existent edge is silent, missing vertex exception
void testRemoveEdge() {
  AdjacencyList<std::string> unDirectedGraph(NOT_DIRECTED, NOT_WEIGHTED);
  AdjacencyList<std::string> directedGraph(DIRECTED, WEIGHTED);

  unDirectedGraph.addVertex("A");
  unDirectedGraph.addVertex("B");

  directedGraph.addVertex("A");
  directedGraph.addVertex("B");
  directedGraph.addVertex("C");

  unDirectedGraph.addEdge("A", "B");

  assert(unDirectedGraph.hasEdge("A", "B"));
  assert(unDirectedGraph.hasEdge("B", "A"));

  unDirectedGraph.removeEdge("B", "A");

  assert(!unDirectedGraph.hasEdge("A", "B"));
  assert(!unDirectedGraph.hasEdge("B", "A"));

  directedGraph.addEdge("A", "B", 10);
  directedGraph.addEdge("B", "A", 20);

  directedGraph.removeEdge("A", "B");

  assert(!directedGraph.hasEdge("A", "B"));
  assert(directedGraph.hasEdge("B", "A"));

  assert(!throwsInvalidArgument([&] {
    directedGraph.removeEdge("A", "C");
  }));
  
  assert(throwsInvalidArgument([&] {
    unDirectedGraph.removeEdge("A", "D");
  }));
}

// tests: out degree and neighbor list (insertion order), vertex without edges
void testGetAdjacentVerticesAndOutDegree() {
  AdjacencyList<std::string> graph(NOT_DIRECTED, NOT_WEIGHTED);
  graph.addVertex("A");
  graph.addVertex("B");
  graph.addVertex("C");
  graph.addVertex("D");

  graph.addEdge("A", "B");
  graph.addEdge("A", "C");

  assert(graph.getOutDegree("A") == 2);
  assert(graph.getOutDegree("B") == 1);
  assert(graph.getOutDegree("D") == 0);

  std::vector<std::string> expected = {"B", "C"};
  assert(graph.getAdjacentVertices("A") == expected);
  assert(graph.getAdjacentVertices("D").empty());
}

int main() {
  testAddVertex();
  testAddEdge();
  testRemoveVertex();
  testRemoveEdge();
  testGetAdjacentVerticesAndOutDegree();
}