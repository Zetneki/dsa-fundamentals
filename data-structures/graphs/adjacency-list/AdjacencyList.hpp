#pragma once
#include <vector>

template  <typename T, typename W = int>
class AdjacencyList {
public:
  explicit AdjacencyList(bool directed = false, bool weighted = false);

	void addVertex(const T &vertex);
	void removeVertex(const T &vertex);
	void addEdge(const T &from, const T &to, W weight = W{1});
	void removeEdge(const T &from, const T &to);
	bool hasEdge(const T &from, const T &to) const;
	bool hasVertex(const T &vertex) const;
	int getOutDegree(const T &vertex) const;
	std::vector<T> getAdjacentVertices(const T &vertex) const;

private:
	struct Edge {
		T to;
		W weight;
	};
	struct Vertex {
		T value;
		std::vector<Edge> edges;
	};

	std::vector<Vertex> m_vertices;
	bool m_directed;
	bool m_weighted;

	int indexOf(const T &vertex) const;
};

#include "AdjacencyList.ipp"