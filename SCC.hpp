#include <unordered_map>
#include "TopoSort.hpp"
#ifndef SCC_H
#define SCC_H

class SCC {
private:
    Graph* G;
    std::vector<int> sentinel;
    std::vector<bool> visited;
    void explore(int v, int s);
    void explore(int v);
public:
    SCC(Graph* G);
    void generateSCCs();
    int getSentinel(int v);
    std::vector<std::vector<int>> getSCCs();
};
#endif
