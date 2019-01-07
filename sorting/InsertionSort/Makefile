all: test

test: test.o InsertionSort.o
	g++ -o test test.o InsertionSort.o

test.o: test.cpp
	g++ -c test.cpp

InsertionSort.o: InsertionSort.cpp InsertionSort.hpp
	g++ -c InsertionSort.cpp
