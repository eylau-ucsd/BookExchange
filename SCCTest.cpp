#include "SCCTest.hpp"

void SCCTest::test1() {
    Graph testGraph (12);
    testGraph.addEdge(0, 2);
    testGraph.addEdge(1, 4);
    testGraph.addEdge(1, 10);
    testGraph.addEdge(1, 6);
    testGraph.addEdge(2, 6);
    testGraph.addEdge(3, 4);
    testGraph.addEdge(3, 2);
    testGraph.addEdge(3, 11);
    testGraph.addEdge(4, 8);
    testGraph.addEdge(4, 0);
    testGraph.addEdge(5, 3);
    testGraph.addEdge(5, 9);
    testGraph.addEdge(6, 0);
    testGraph.addEdge(7, 5);
    testGraph.addEdge(7, 8);
    testGraph.addEdge(8, 11);
    testGraph.addEdge(9, 7);
    testGraph.addEdge(9, 10);
    testGraph.addEdge(10, 11);
    testGraph.addEdge(10, 2);
    testGraph.addEdge(11, 1);
    SCC testSCC (&testGraph);
    testSCC.generateSCCs();
    assert (testSCC.getSentinel(0) == testSCC.getSentinel(2));
    assert (testSCC.getSentinel(0) == testSCC.getSentinel(6));
    assert (testSCC.getSentinel(1) == testSCC.getSentinel(4));
    assert (testSCC.getSentinel(1) == testSCC.getSentinel(8));
    assert (testSCC.getSentinel(1) == testSCC.getSentinel(10));
    assert (testSCC.getSentinel(1) == testSCC.getSentinel(11));
    assert (testSCC.getSentinel(5) == testSCC.getSentinel(7));
    assert (testSCC.getSentinel(5) == testSCC.getSentinel(9));
    std::vector<std::vector<int>> SCCs = testSCC.getSCCs();
    assert (SCCs.size() == 4);
}

int main() {
    SCCTest testInstance;
    testInstance.test1();
    std::cout << "Test 1 passed" << std::endl;
    return 0;
}
