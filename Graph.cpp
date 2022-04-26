#include "Graph.hpp"
Graph::Graph(int size) {
    neighbors = std::vector<std::vector<int>> (size, std::vector<int>());
    n = size;
}

std::vector<int> Graph::getNeighbors(int v) {
    if (v >= n) {
        std::vector<int> result;
        result.push_back(-1);
        return result;
    }
    return neighbors[v];
}

bool Graph::addEdge(int v1, int v2) {
    if (v1 >= n || v2 >= n) {
        return false;
    }
    neighbors[v1].push_back(v2);
    return true;
}

int Graph::size() {
    return n;
}
