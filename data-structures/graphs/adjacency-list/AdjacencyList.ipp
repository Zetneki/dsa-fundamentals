#pragma once

// constructor initializes m_bool and m_weighted
template <typename T, typename W>
AdjacencyList<T, W>::AdjacencyList(bool directed, bool weighted) : m_directed(directed), m_weighted(weighted) {}

// creates a Vertex type object with the given value as the name and adds it to m_vertices
// returns if the given value is already in m_vertices
template<typename T, typename W>
void AdjacencyList<T, W>::addVertex(const T &vertex) {
  if (hasVertex(vertex)) return;
  m_vertices.push_back(Vertex{vertex, {}});
}

// removes vertex from m_vertices
// checks the edges of the m_vertices elements and removes the ones equal to vertex
// throws exception if the given value isn't found in m_vertices
template<typename T, typename W>
void AdjacencyList<T, W>::removeVertex(const T &vertex) {
  int index = indexOfVertex(vertex);
  if (index == -1) throw std::invalid_argument("Vertex not found at removeVertex");

  m_vertices.erase(m_vertices.begin() + index);

  for (auto &v: m_vertices) {
    std::erase_if(v.edges, [&vertex](const auto &edge) {
      return edge.to == vertex;
    });
  }
}

// creates an edge type object and adds it to edges
// if the edges contain the exact edge already, it returns
// if m_weighted is false then it only gives 1 as weight otherwise the given value
// based on m_directed only one or both directions are given to the edges
// throws exception if either vertex is not found or if you want to add the same value as the vertex for the edge
template<typename T, typename W>
void AdjacencyList<T, W>::addEdge(const T &from, const T &to, W weight) {
  if (from == to) throw std::invalid_argument("Can not add edge loop, meaning that the two given values can't be the same");

  int fromIndex = indexOfVertex(from);
  int toIndex = indexOfVertex(to);
  if (fromIndex == -1 || toIndex == -1) throw std::invalid_argument("Vertex not found at addEdge");

  if (hasEdge(from, to)) return;

  if (!m_weighted) weight = W{1};

  m_vertices[fromIndex].edges.push_back(Edge{to, weight});
  if (!m_directed) m_vertices[toIndex].edges.push_back(Edge{from, weight});
}

// removes the edge from the given vertex
// if not directed then it gets removed from the other side as well (edge used as vertex and vertex used as edge)
// throws exception if either vertex is not found
template<typename T, typename W>
void AdjacencyList<T, W>::removeEdge(const T &from, const T &to) {
  int fromIndex = indexOfVertex(from);
  int toIndex = indexOfVertex(to);
  if (fromIndex == -1 || toIndex == -1) throw std::invalid_argument("Vertex not found at removeEdge");

  auto &edgesFrom = m_vertices[fromIndex].edges;
  auto &edgesTo = m_vertices[toIndex].edges;

  std::erase_if(edgesFrom, [&to](const auto &edge) {
    return edge.to == to;
  });
  if (!m_directed) {
    std::erase_if(edgesTo, [&from](const auto &edge) {
    return edge.to == from;
  });
  }
}

// returns the index value of the vertex from the m_vertices
// returns -1 if the given value isn't found
template<typename T, typename W>
int AdjacencyList<T, W>::indexOfVertex(const T &vertex) const {
  for (std::size_t i = 0; i < m_vertices.size(); i++) {
    if (m_vertices[i].value == vertex) return static_cast<int>(i);
  }
  return -1;
}

// returns the index value of the edge from the given vertex
// returns -1 if the requested edge isn't found
template<typename T, typename W>
int AdjacencyList<T, W>::indexOfEdge(const T &from, const T &to) const {
  int index = indexOfVertex(from);
  if (index == -1) throw std::invalid_argument("Vertex not found at indexOfEdge");

  auto &edges = m_vertices[index].edges;

  for (std::size_t i = 0; i < edges.size(); ++i) {
    if (edges[i].to == to) return static_cast<int>(i);
  }
  return -1;
}

// returns true if the adjacency list has the given vertex
// otherwise it returns false
template<typename T, typename W>
bool AdjacencyList<T, W>::hasVertex(const T &vertex) const {
  return indexOfVertex(vertex) != -1;
}

// returns true if the vertex has the given edge
// otherwise it returns false
template<typename T, typename W>
bool AdjacencyList<T, W>::hasEdge(const T &from, const T &to) const {
  return indexOfEdge(from, to) != -1;
}

// prints out the graph
// T must support operator== and operator<< (e.g. int, std::string, or a custom type that defines them). W must support operator<<.
template<typename T, typename W>
void AdjacencyList<T, W>::printGraph(std::ostream &out) const {
  out << (m_directed ? "Directed" : "Undirected") << " Graph Adjacency List:" << std::endl;

  for (auto &vert: m_vertices) {

    out << vert.value << ": ";

    for (auto &e: vert.edges) {
      if (m_weighted) out << e.to << " -(" << e.weight << ")-> ";
      else out << e.to << " -> ";
    }

    out << "NULL" << std::endl;
  }
}

// addVertex(vertex): új csúcsot vesz fel üres éllistával. Ha már van ilyen csúcs, nem csinál semmit (vagy hibát dob), hogy ne legyen duplikáció.
// removeVertex(vertex): törli a csúcsot a m_vertices-ből, és az összes többi csúcs éllistájából kiveszi azokat az éleket, amelyek rá mutatnak.
// addEdge(from, to, weight): hozzáad egy Edge{to, weight}-et a from csúcs éllistájához. Irányítatlan gráfnál a to csúcs listájához is hozzáad egy Edge{from, weight}-et.
// removeEdge(from, to): kiveszi a from listájából a to-ra mutató élt, irányítatlannál fordítva is.
// hasEdge(from, to): igaz, ha a from éllistájában van to célú él.
// hasVertex(vertex): igaz, ha a csúcs létezik (indexOfVertex(vertex) != -1).
// getOutDegree(vertex): a csúcs éllistájának mérete.
// getAdjacentVertices(vertex): a csúcs éllistájából kigyűjti a to értékeket, és std::vector<T>-ként visszaadja.
// printGraph: kirajzolja a gráfot:
  // Undirected Graph Adjacency List:
  // 0: 1 -> 2 -> NULL
  // 1: 0 -> 2 -> NULL
  // 2: 0 -> 1 -> NULL
  //
  // Directed Graph Adjacency List:
  // 0: NULL
  // 1: 2 -> 0 -> NULL
  // 2: 0 -> NULL