//
// Created by Ananya Karra on 2/29/24.
//

#ifndef TOP_SORT_HPP
#define TOP_SORT_HPP

#include <vector>
#include <unordered_set>

void dfs(int &at, std::vector<bool> visited, std::vector<int> visitedNodes, std::vector<int>&graph) {
    visited[at] = true;
    std::unordered_set<int> edges = {1, 2, 3, 4, 5, 6}; /// get temporary edges
    for (auto const edge: edges) {
        if (!visited[edge.to]) {
            dfs(edge.to, visited, visitedNodes, graph);
        }
    }
    visitedNodes.add(at);
}

// have graph be a class that you use to call TopSort on
std::vector<unsigned> TopSort(std::vector<int>&graph) {
    const size_t N = graph.size();
    std::vector<bool> visited(N);
    std::vector<unsigned> ordering(N);
    size_t i = N - 1; // index for ordering the array

    for (int at = 0; at < N; at++ ) {
        if (!visited[at]) {
            std::vector<int> visitedNodes;
            dfs(at, visited, visitedNodes, graph);
            for (auto const nodeId: visitedNodes) {
                ordering[i] = nodeId;
                i = i - 1;
            }
        }
    }
    return ordering;
}


#endif
