#include <vector>
#ifndef GRAPH_H
#define GRAPH_H

class Graph {
private:
    std::vector<std::vector<int>> neighbors; // adjacency list
    int n;
public:
    Graph(int size);
    std::vector<int> getNeighbors(int v);
    bool addEdge(int v1, int v2);
    int size();
};
#endif
