CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -Werror -pedantic -g

all: testGraph

testGraph: testGraph.cpp graph.hpp
	$(CC) $(CFLAGS) -o testGraph testGraph.cpp

.PHONY: clean

clean:
	rm -rf *.o testGraph *~
