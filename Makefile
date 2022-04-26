CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=BookExchange

all: $(OUTFILES)

BookExchange: BookExchange.cpp SCC.cpp SCC.hpp TopoSort.cpp TopoSort.hpp Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -o BookExchange BookExchange.cpp SCC.cpp TopoSort.cpp Graph.cpp

SCCTest: SCCTest.cpp SCC.cpp SCC.hpp TopoSort.cpp TopoSort.hpp Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -o SCCTest SCCTest.cpp SCC.cpp TopoSort.cpp Graph.cpp

clean:
	$(RM) $(OUTFILES) *.o
