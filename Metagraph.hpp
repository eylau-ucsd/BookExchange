#include "SCC.hpp"
#include <unordered_map>
#ifndef METAGRAPH_H
#define METAGRAPH_H
class Metagraph {
private:
    Graph* metaG;
    SCC* components;
    std::unordered_map<int, int> superVertexMap; // maps sentinels to supervertexmaps
public:
    Metagraph(Graph* G);
    ~Metagraph();
    int getSuperVertex(int v);
    Graph* getMetagraph();
};
#endif
