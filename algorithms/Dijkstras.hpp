#ifndef DIJKSTRAS_HPP
#define DIJKSTRAS_HPP

#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

std::unordered_set<std::string> computeAdjacent(std::string &current);

// would have this snippet declared within a class already
struct Node { // should not be declared here (should be declared within class and inside algorithm below
    std::string value;
    int distance{0};
    Node *predV{nullptr};
};

// more or less pseudocode -- can modify to task at hand
std::vector<std::string> DijkstraShortestPath(Node *&startV, const std::unordered_set<Node>& graph) {

    std::priority_queue<Node> unvisitedQueue;
    for (auto currentV: graph) {
        currentV->distance = 123456789; // use large number for upper bound
        currentV->predV = nullptr;
        unvisitedQueue.push(currentV);
    }
    startV->distance = 0;
    std::unordered_map<Node, Node> mapping;
    while (!unvisitedQueue.empty()) {
        std::string top = unvisitedQueue.top().value;
        unvisitedQueue.pop();

        std::unordered_set<std::string> adjacentWords;
        for (auto const &adjV: adjacentWords) {
            int edgeWeight = top->distance + 1;
            int alternativePathDistance = currentV->distance + edgeWeight;
            // if there is a shorter path: update the predecessor
            if (alternativePathDistance < adjV->distance) {
                adjV->distance = alternativePathDistance;
                adj->predV = currentV;
            }
        }
    }
}


#endif
