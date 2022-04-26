#include "SCC.hpp"

void SCC::explore(int v, int s) {
    visited[v] = true;
    sentinel[v] = s;
    for (int w : G->getNeighbors(v)) {
        if (!visited[w]) {
            explore(w, s);
        }
    }
}

void SCC::explore(int v) {
    explore(v, v);
}

SCC::SCC(Graph* G) {
    this->G = G;
}

Graph* transposed(Graph* G) {
    Graph* transG = new Graph(G->size());
    for (int v = 0; v < G->size(); v++) {
        for (int w : G->getNeighbors(v)) {
            transG->addEdge(w, v);
        }
    }
    return transG;
}

void SCC::generateSCCs() {
    sentinel = std::vector<int> (G->size(), -1);
    for (int i = 0; i < sentinel.size(); i++) {
        sentinel[i] = i;
    }
    visited = std::vector<bool> (G->size(), false);
    TopoSort TopoTransG = TopoSort(transposed(G));
    std::vector<int> order = TopoTransG.getOrder();
    for (int v : order) {
        if (!visited[v]) {
            explore(v);
        }
    }
}

int SCC::getSentinel(int v) {
    return sentinel[v];
}

std::vector<std::vector<int>> SCC::getSCCs() {
    std::unordered_map<int, std::vector<int>> SCCMap;
    for (int v = 0; v < G->size(); v++) {
        if (SCCMap.count(sentinel[v]) == 0) {
            std::vector<int> newSCC;
            newSCC.push_back(v);
            SCCMap.emplace(sentinel[v], newSCC);
        }
        else {
            SCCMap.find(sentinel[v])->second.push_back(v);
        }
    }
    std::vector<std::vector<int>> SCCs;
    for (std::pair<int, std::vector<int>> pair : SCCMap) {
        SCCs.push_back(pair.second);
    }
    return SCCs;
}
