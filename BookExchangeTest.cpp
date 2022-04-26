#include "BookExchangeTest.hpp"
void BookExchangeTest::test1() {
    Graph books (5);
    books.addEdge(0, 1);
    books.addEdge(1, 2);
    books.addEdge(2, 3);
    books.addEdge(3, 4);
    BookExchange testExchange(&books);
    bool answer = testExchange.isPossible(std::vector<int> {4, 2, 5});
    assert (answer);
}

void BookExchangeTest::test2() {
    Graph books (5);
    books.addEdge(0, 1);
    books.addEdge(1, 2);
    books.addEdge(3, 4);
    BookExchange testExchange(&books);
    bool answer1 = testExchange.isPossible(std::vector<int> {0, 2, 1});
    bool answer2 = testExchange.isPossible(std::vector<int> {0, 2, 3});
    assert (answer1);
    assert (!answer2);
}

void BookExchangeTest::test3() {
    Graph books (6);
    books.addEdge(0, 1);
    books.addEdge(1, 3);
    books.addEdge(1, 2);
    books.addEdge(2, 4);
    books.addEdge(3, 5);
    BookExchange testExchange(&books);
    bool answer1 = testExchange.isPossible(std::vector<int> {0, 1, 3, 5});
    bool answer2 = testExchange.isPossible(std::vector<int> {0, 1, 2, 4});
    bool answer3 = testExchange.isPossible(std::vector<int> {0, 1, 3, 4});
    bool answer4 = testExchange.isPossible(std::vector<int> {0, 1, 2, 5});
    assert (answer1);
    assert (answer2);
    assert (!answer3);
    assert (!answer4);
}

int main() {
    BookExchangeTest testInstance;
    testInstance.test1();
    std::cout << "Test 1 passed" << std::endl;
    testInstance.test2();
    std::cout << "Test 2 passed" << std::endl;
    testInstance.test3();
    std::cout << "Test 3 passed" << std::endl;
    return 0;
}
