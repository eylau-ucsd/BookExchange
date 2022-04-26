#include "Graph.hpp"
#ifndef TOPOSORT_H
#define TOPOSORT_H
class TopoSort {
private:
    Graph* G;
    std::vector<bool> visited;
    std::vector<int> postOrder;
    void explore(int v);
    void DFS();
public:
    TopoSort(Graph* G);
    std::vector<int> getOrder();
};
#endif
