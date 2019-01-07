#ifndef NODE_CPP
#define NODE_CPP

#include "Node.hpp"

Node::Node(int data) {
  this -> data = data;
  this -> right = NULL;
  this -> left = NULL;
}

Node::Node() {
  this -> data = 0;
  this -> right = NULL;
  this -> left = NULL;
}

int Node::getData() {
  return this -> data;
}

void Node::setData(int data) {
  this -> data = data;
}

Node* Node::getNext() {
  return this -> next;
}

void Node::setNext(Node* next) {
  this -> next = next;
}

#endif
