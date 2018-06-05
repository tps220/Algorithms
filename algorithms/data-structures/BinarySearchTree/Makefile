all: test

test: main.o Node.o BinarySearchTree.o
	g++ main.o Node.o BinarySearchTree.o -o test

main: main.cpp Node.o BinarySearchTree.o
	g++ -c main.cpp

BinarySearchTree: Node.o BinarySearchTree.cpp BinarySearchTree.hpp
	g++ -c BinarySearchTree.cpp

Node: Node.cpp Node.hpp
	g++ -c Node.cpp
