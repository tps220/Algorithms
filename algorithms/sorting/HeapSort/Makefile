all: test

test: HeapSort.o test.o
	g++ HeapSort.o test.o -o test
test.o: HeapSort.o test.cpp
	g++ -c test.cpp
HeapSort.o: HeapSort.hpp HeapSort.cpp
	g++ -c HeapSort.cpp

