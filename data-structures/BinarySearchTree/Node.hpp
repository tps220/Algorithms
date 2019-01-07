#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

class Node {
public:
  Node(int data);
  Node();
  Node* right;
  Node* left;
  int getData();
  void setData(int data);

  //methods
  Node* getNext();
  void setNext(Node* next);
private:
  int data;

  //used for connect_perfect_tree and connect methods
  Node* next;
};

#endif
