//
// Created by Ananya Karra on 3/24/24.
//

#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

template<typename T>
class Graph {
public:
    [[nodiscard]] Graph();
    ~Graph();
    void addEdge(T source, T dest);
    void addVertex(T vertex);
    void removeVertex(T source);
    void removeEdge(T source, T dest);
    std::unordered_set<T> neighbors(T vertex);
private:
    std::unordered_map<T, std::unordered_set<T>> mapping;
    size_t count{0};
};

template<typename T>
Graph<T>::Graph() = default;

template<typename T>
Graph<T>::~Graph() = default;

template<typename T>
void Graph<T>::addVertex(T vertex) {
    if (!mapping.contains(vertex)) {
        std::unordered_set<T> n;
        mapping[vertex] = n;
    }
}

template<typename T>
void Graph<T>::addEdge(T source, T dest) {
    mapping[source].insert(dest);
    mapping[dest].insert(source);
}

template<typename T>
void Graph<T>::removeEdge(T source, T dest) {
    mapping.at(source).erase(dest);
    mapping.at(dest).erase(source);
}

template<typename T>
void Graph<T>::removeVertex(T source) {
    mapping.erase(source);
}

template<typename T>
std::unordered_set<T> Graph<T>::neighbors(T vertex) {
    return mapping.at(vertex);
}

// use a load function that loads everything into the graph

inline Graph<std::string> loadGraph() {
    Graph<std::string> iGraph;
    // load contents into the graph // based on csv file format
    return iGraph;
}

/// we need some sort of a target that tells
// mapping if it was the correct mapping in the first place
template<typename T> // keep a mapping and convert the mapping into a vector
inline bool BFS(T start_node) {
    Graph<std::string> igraph = loadGraph();
    // arbitrary start node provided to algorithm
    std::queue<T> Q;
    std::unordered_set<T> visited;
    Q.enqueue(start_node);
    visited.insert(start_node);

    while (!Q.empty()) {
        T v = Q.deuqueue();
        std::unordered_set<T> adjToV = igraph.neighbors(v);
        for (auto const &w: adjToV) {
            if (!visited.contains(w)) {
                Q.enqueue(w);
                visited.insert(w);
            } // if it is a shorter path than the one before
            // then add it, otherwise, keep the one we are using right now
        }
    }
    return true;
}

// we also need to know if the DFS algorithm we are using
// can support other sequence type searches
template<typename T>
inline bool DFS(Graph<std::string> &igraph, T start_node) {
    std::unordered_set<T> visited;
    visited.insert(start_node);
    std::unordered_set<T> adjToStart = igraph.neighbors(start_node);
    for (auto const &w : adjToStart) {
        if (!visited.contains(w)) {
            DFS(igraph, w);
        }
    }
}
