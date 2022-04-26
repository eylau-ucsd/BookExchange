CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=main BookExchangeTest SCCTest

all: $(OUTFILES)

main:	main.cpp BookExchange.cpp Metagraph.cpp Metagraph.hpp SCC.cpp SCC.hpp \
		TopoSort.cpp TopoSort.hpp Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS?) -o main main.cpp BookExchange.cpp Metagraph.cpp \
	SCC.cpp TopoSort.cpp Graph.cpp

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
