#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include <sstream>
#include "BinaryTree.hpp"

BinaryTree::BinaryTree() {
  this -> data = 0;
  this -> left = NULL;
  this -> right = NULL;
}
BinaryTree::BinaryTree(int data) {
  this -> data = data;
  this -> left = NULL;
  this -> right = NULL;
}

BinaryTree::BinaryTree(int data, BinaryTree* left, BinaryTree* right) {
  this -> data = data;
  this -> left = left;
  this -> right = right;
}

int BinaryTree::getData() {
  return this -> data;
}

void BinaryTree::setData(int data) {
  this -> data = data;
}

std::string BinaryTree::toString() {
  std::ostringstream ss;
  ss << this -> data;
  return ss.str();
}


#endif
