CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=BookExchangeTest SCCTest

all: $(OUTFILES)

BookExchangeTest:	BookExchangeTest.cpp BookExchangeTest.hpp BookExchange.cpp \
					Metagraph.cpp Metagraph.hpp SCC.cpp SCC.hpp TopoSort.cpp \
					TopoSort.hpp Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS?) -o BookExchangeTest BookExchangeTest.cpp \
	BookExchange.cpp Metagraph.cpp SCC.cpp TopoSort.cpp Graph.cpp

SCCTest:	SCCTest.cpp SCCTest.hpp SCC.cpp SCC.hpp TopoSort.cpp TopoSort.hpp \
			Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS?) -o SCCTest SCCTest.cpp SCC.cpp TopoSort.cpp Graph.cpp

clean:
	$(RM) $(OUTFILES) *.o
