#include "Graph.hpp"
Graph::Graph(int size) {
    neighbors = std::vector<std::unordered_set<int>> (size, std::unordered_set<int> ());
    n = size;
}

std::vector<int> Graph::getNeighbors(int v) {
    std::vector<int> result;
    if (v >= n) {
        result.push_back(-1);
        return result;
    }
    for (int w : neighbors[v]) {
        result.push_back(w);
    }
    return result;
}

bool Graph::addEdge(int v1, int v2) {
    if (v1 >= n || v2 >= n) {
        return false;
    }
    if (neighbors[v1].count(v2) == 1) {
        return false;
    }
    neighbors[v1].insert(v2);
    return true;
}

int Graph::size() {
    return n;
}
