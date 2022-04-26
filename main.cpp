#include "BookExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

BookExchange parseBookExchange (std::ifstream& input, Graph*& G) {
    std::string line;
    std::getline(input, line);
    G = new Graph (std::stoi(line));
    std::getline(input, line);
    while (getline(input, line) && line.size() != 0) {
        int delimPos = line.find(',');
        int v1 = std::stoi(line.substr(0, delimPos));
        int v2 = std::stoi(line.substr(line.find(',') + 1,
        line.size() - delimPos - 1));
        G->addEdge(v1, v2);
    }
    return BookExchange (G);
}

std::vector<int> parseWishList (std::ifstream& input) {
    std::string line;
    std::vector<int> wishList;
    while (getline(input, line) && line.size() != 0) {
        wishList.push_back(std::stoi(line));
    }
    return wishList;
}

int main(int argc, char *argv[]) {
    std::ifstream input (std::string(argv[1]), std::ifstream::in);
    Graph* G;
    BookExchange BookEx = parseBookExchange(input, G);
    std::string line;
    std::vector<int> wishList = parseWishList(input);
    if (BookEx.isPossible(wishList)) {
        std::cout << "Yes, wish list can be fulfilled with the book exchange" << std::endl;
    }
    else {
        std::cout << "No, wish list cannot be fulfilled with the book exchange" << std::endl;
    }
    delete G;
    G = nullptr;
    return 0;
}
