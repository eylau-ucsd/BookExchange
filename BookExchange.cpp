#include "BookExchange.hpp"
BookExchange::BookExchange(Graph* G) {
    this->G = G;
}

std::vector<int> sortedByOrder (std::vector<int> list, std::vector<int> order) {
    std::unordered_set<int> bucket;
    for (int v : list) {
        bucket.insert(v);
    }
    std::vector<int> orderedList;
    for (int v : order) {
        if (bucket.count(v) == 1) {
            orderedList.push_back(v);
        }
    }
    return orderedList;
}

void BookExchange::explore(int v) {
    visited[v] = true;
    for (int w : metaG->getNeighbors(v)) {
        if (!visited[w]) {
            explore(w);
        }
    }
}

bool BookExchange::isPossible(std::vector<int> wishList) {
    if (wishList.size() < 2) {
        return true;
    }
    Metagraph meta = Metagraph(G);
    metaG = meta.getMetagraph();
    TopoSort sorter = TopoSort(meta.getMetagraph());
    std::vector<int> metaList;
    for (int v : wishList) {
        metaList.push_back(meta.getSuperVertex(v));
    }
    std::vector<int> sortedList = sortedByOrder(metaList, sorter.getOrder());
    visited = std::vector<bool> (metaG->size(), false);
    for (int i = sortedList.size()-2; i > -1; i--) {
        if (sortedList[i] == sortedList[i+1]) continue;
        visited[sortedList[i+1]] = false;
        explore(sortedList[i]);
        if (!visited[sortedList[i+1]]) {
            metaG = nullptr;
            return false;
        }
    }
    metaG = nullptr;
    return true;
}
