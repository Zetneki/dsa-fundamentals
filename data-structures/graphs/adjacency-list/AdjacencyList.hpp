#pragma once

#include <vector>
#include <stdexcept>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <type_traits>

#define DIRECTED true
#define NOT_DIRECTED false
#define WEIGHTED true
#define NOT_WEIGHTED false

template <typename T, typename W = int>
class AdjacencyList {
	static_assert(std::is_arithmetic_v<W>, "W must be a numeric type (int, double, ...)");

public:
  explicit AdjacencyList(bool directed = false, bool weighted = false);

	void addVertex(const T &vertex);
	void removeVertex(const T &vertex);
	void addEdge(const T &from, const T &to, W weight = W{1});
	void removeEdge(const T &from, const T &to);
	bool hasEdge(const T &from, const T &to) const;
	bool hasVertex(const T &vertex) const;
	std::size_t getOutDegree(const T &vertex) const;
	std::vector<T> getAdjacentVertices(const T &vertex) const;
	void printGraph(std::ostream &out = std::cout) const;

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

	int indexOfVertex(const T &vertex) const;
	int indexOfEdge(const T &from, const T &to) const;
};

#include "AdjacencyList.ipp"