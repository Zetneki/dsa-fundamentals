# Graphs

## What is a Graph?

A graph is a data structure that consists of vertices (nodes) and
edges that connect pairs of vertices. It models relationships between
objects, such as roads between cities or links between web pages.

## Terminology

- **Vertex**: a node of the graph
- **Edge**: a connection between two vertices
- **Neighbors (adjacent vertices)**: vertices connected by an edge
- **Degree**: the number of edges of a vertex (out-degree in a directed graph)

## Types

- Undirected graph: an edge connects two vertices in both directions
- Directed graph: an edge goes from one vertex to another, in one direction only
- Unweighted graph: edges carry no extra information
- Weighted graph: every edge has a weight (cost, distance, ...)

## Representations

- Adjacency List
- Adjacency Matrix

## Comparison

V is the number of vertices, E is the number of edges, deg(v) is the
number of edges of vertex v.

| Feature              | Adjacency List | Adjacency Matrix |
|----------------------|----------------|------------------|
| Space                | O(V + E)       | O(V^2)           |
| Check if edge exists | O(deg(v))      | O(1)             |
| List neighbors       | O(deg(v))      | O(V)             |
| Add edge             | O(1)           | O(1)             |
| Remove edge          | O(deg(v))      | O(1)             |
| Add vertex           | O(1) amortized | O(V^2) resize    |
| Best for             | Sparse graphs  | Dense graphs     |

The complexities above are the textbook values for vertices identified
by index. This `AdjacencyList` supports generic vertex types, so every
operation first has to find the vertex, which adds O(V) (see the
Adjacency List documentation).

## When to use?

- Use an adjacency list when the graph is sparse (few edges compared to V^2)
  and you mostly iterate over neighbors (BFS, DFS).
- Use an adjacency matrix when the graph is dense or you need to check
  very quickly whether an edge exists.