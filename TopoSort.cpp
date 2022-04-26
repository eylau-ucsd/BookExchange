#include "TopoSort.hpp"
void TopoSort::explore(int v) {
    visited[v] = true;
    for (int neighbor : G->getNeighbors(v)) {
        if (!visited[neighbor]) {
            explore(neighbor);
        }
    }
    postOrder.push_back(v);
}

void TopoSort::DFS() {
    for (int v = 0; v < G->size(); v++) {
        if (!visited[v]) {
            explore(v);
        }
    }
}

TopoSort::TopoSort(Graph* G) {
    this->G = G;
}

std::vector<int> TopoSort::getOrder() {
    visited = std::vector<bool> (G->size(), false);
    std::vector<int> topoOrder;
    postOrder.clear();
    DFS();
    for (int i = postOrder.size()-1; i > -1; i--) {
        topoOrder.push_back(postOrder[i]);
    }
    return topoOrder;
}
