all: test

test: main.o Trie.o
	g++ main.o Trie.o -o test
main.o: main.cpp Trie.cpp Trie.hpp Trie.o
	g++ -c main.cpp
Trie.o: Trie.cpp Trie.hpp
	g++ -c Trie.cpp
