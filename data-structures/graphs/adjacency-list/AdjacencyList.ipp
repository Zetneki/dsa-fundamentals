#pragma once

// constructor initializes m_bool and m_weighted
template <typename T, typename W>
AdjacencyList<T, W>::AdjacencyList(bool directed, bool weighted) : m_directed(directed), m_weighted(weighted) {}

// creates a Vertex type object with the given value as the name and adds it to m_vertices
// returns if the given value is already in m_vertices
template<typename T, typename W>
void AdjacencyList<T, W>::addVertex(const T &vertex) {
  if (indexOf(vertex) != -1) return;
  m_vertices.push_back(Vertex{vertex, {}});
}

// removes vertex from m_vertices
// checks the edges of the m_vertices elements and removes the ones equal to vertex
// throws exception if the given value isn't found in m_vertices
template<typename T, typename W>
void AdjacencyList<T, W>::removeVertex(const T &vertex) {
  int index = indexOf(vertex);
  if (index == -1) throw std::invalid_argument("Vertex not found");

  m_vertices.erase(m_vertices.begin() + index);

  for (auto &v: m_vertices) {
    for (std::size_t i = 0; i < v.edges.size(); ) {
      if (v.edges[i].to == vertex) v.edges.erase(v.edges.begin() + i);
      else ++i;
    }
  }
}

// creates an edge type object and adds it to edges
// if m_weighted is false then it only gives 1 as weight otherwise the given value
// based on m_directed only one or both directions are given to the edges
// if both of the indexes are already in it exception is thrown
template<typename T, typename W>
void AdjacencyList<T, W>::addEdge(const T &from, const T &to, W weight) {
  int fromIndex = indexOf(from);
  int toIndex = indexOf(to);
  if (fromIndex == -1 || toIndex == -1) throw std::invalid_argument("Vertex not found");

  if (!m_weighted) weight = W{1};

  m_vertices[fromIndex].edges.push_back(Edge{to, weight});
  if (!m_directed) m_vertices[toIndex].edges.push_back(Edge{from, weight});
}

// returns the index value of the vertex from the m_vertices
// returns -1 if the given value isn't found
template<typename T, typename W>
int AdjacencyList<T, W>::indexOf(const T &vertex) const {
  for (std::size_t i = 0; i < m_vertices.size(); i++) {
    if (m_vertices[i].value == vertex) return static_cast<int>(i);
  }
  return -1;
}

// addVertex(vertex): új csúcsot vesz fel üres éllistával. Ha már van ilyen csúcs, nem csinál semmit (vagy hibát dob), hogy ne legyen duplikáció.
// removeVertex(vertex): törli a csúcsot a m_vertices-ből, és az összes többi csúcs éllistájából kiveszi azokat az éleket, amelyek rá mutatnak.
// addEdge(from, to, weight): hozzáad egy Edge{to, weight}-et a from csúcs éllistájához. Irányítatlan gráfnál a to csúcs listájához is hozzáad egy Edge{from, weight}-et.
// removeEdge(from, to): kiveszi a from listájából a to-ra mutató élt, irányítatlannál fordítva is.
// hasEdge(from, to): igaz, ha a from éllistájában van to célú él.
// hasVertex(vertex): igaz, ha a csúcs létezik (indexOf(vertex) != -1).
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