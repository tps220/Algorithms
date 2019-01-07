all: test

test: QuickSort.o test.o
	g++ QuickSort.o test.o -o test
test.o: QuickSort.o test.cpp
	g++ -c test.cpp
QuickSort.o: QuickSort.hpp QuickSort.cpp
	g++ -c QuickSort.cpp

