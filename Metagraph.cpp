#include "Metagraph.hpp"

Metagraph::Metagraph(Graph* G) {
    components = new SCC(G);
    components->generateSCCs();
    std::vector<std::vector<int>> SCCList = components->getSCCs();
    metaG = new Graph(components->getSCCs().size());
    for (int V = 0; V < (int) SCCList.size(); V++) {
        superVertexMap.emplace(components->getSentinel(SCCList[V][0]), V);
    }
    for (int v = 0; v < (int) G->size(); v++) {
        for (int w : G->getNeighbors(v)) {
            if (getSuperVertex(v) != getSuperVertex(w)) {
                metaG->addEdge(getSuperVertex(v), getSuperVertex(w));
            }
        }
    }
}

Metagraph::~Metagraph() {
    delete components;
    delete metaG;
}

int Metagraph::getSuperVertex(int v) {
    if (superVertexMap.count(components->getSentinel(v)) == 0) {
        return -1;
    }
    return superVertexMap.find(components->getSentinel(v))->second;
}

Graph* Metagraph::getMetagraph(){
    return metaG;
}
