#include "Metagraph.hpp"
#include <unordered_set>
#ifndef BOOKEXCHANGE_H
#define BOOKEXCHANGE_H
class BookExchange {
private:
    std::vector<bool> visited;
    Graph* G;
    Graph* metaG;
    void explore(int v);
public:
    BookExchange(Graph* G);
    bool isPossible(std::vector<int> wishList);
};
#endif
