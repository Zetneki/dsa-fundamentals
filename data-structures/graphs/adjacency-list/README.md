# Adjacency List

## What is an Adjacency List?

An adjacency list is a graph representation where every vertex stores
the list of edges that go out from it.

## Structure

The AdjacencyList contains:

- `m_vertices` - `std::vector` of `Vertex` objects
- `m_directed` - whether the graph is directed
- `m_weighted` - whether the graph is weighted

Each `Vertex` contains:

- `value` - the vertex itself (any type `T`)
- `edges` - `std::vector` of `Edge` objects going out from the vertex

Each `Edge` contains:

- `to` - the target vertex
- `weight` - the weight of the edge (`W`, `int` by default)

Example (`T = std::string`):

    Szeged:   -> Budapest -> Kecskemét -> NULL
    Budapest: -> Szeged -> NULL

In an undirected graph every edge is stored twice (at both vertices),
in a directed graph only at the starting vertex.

## Rules

- A vertex can be added only once
- No loop edges (an edge from a vertex to itself throws `std::invalid_argument`)
- No duplicate edges (adding an existing edge does nothing, the first weight is kept)
- In an unweighted graph the given weight is ignored (stored as 1 and not printed)
- `T` must support `operator==` and `operator<<`, `W` must be a numeric type

## Operations

- `addVertex()`
- `removeVertex()`
- `addEdge()`
- `removeEdge()`
- `hasVertex()`
- `hasEdge()`
- `getOutDegree()`
- `getAdjacentVertices()`
- `printGraph()`

## Time Complexity

V is the number of vertices, E is the number of edges, deg(v) is the
number of edges of vertex v. Because vertices are generic values, every
operation starts with an O(V) search for the vertex.

| Operation           | Complexity                 |
|---------------------|----------------------------|
| addVertex           | O(V)                       |
| removeVertex        | O(V + E)                   |
| addEdge             | O(V + deg(from))           |
| removeEdge          | O(V + deg(from) + deg(to)) |
| hasVertex           | O(V)                       |
| hasEdge             | O(V + deg(from))           |
| getOutDegree        | O(V)                       |
| getAdjacentVertices | O(V + deg(v))              |
| printGraph          | O(V + E)                   |

## Space Complexity

O(V + E)

## When to use?

Use an adjacency list when:

- The graph is sparse
- You mostly need the neighbors of a vertex (BFS, DFS, shortest path)
- Memory usage matters

## Advantages

- Memory efficient for sparse graphs
- Fast iteration over the neighbors of a vertex
- Easy to add new vertices
- Supports generic vertex types, directed and weighted graphs

## Disadvantages

- Checking whether an edge exists is O(deg(v)) instead of O(1)
- Finding a vertex is O(V) with generic vertex types
- Removing a vertex requires going through every edge list
- Getting the incoming edges of a vertex requires scanning all lists

## Implementation Checklist

- [x] Constructor (directed, weighted)
- [x] addVertex()
- [x] removeVertex()
- [x] addEdge()
- [x] removeEdge()
- [x] hasVertex()
- [x] hasEdge()
- [x] getOutDegree()
- [x] getAdjacentVertices()
- [x] printGraph()
- [x] Tests