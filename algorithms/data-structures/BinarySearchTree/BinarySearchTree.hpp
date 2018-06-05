#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <vector>
#include "Node.hpp"

class BinarySearchTree {
public:
  BinarySearchTree();
  BinarySearchTree(int data);
  BinarySearchTree(std::vector<int> data);
  ~BinarySearchTree();
  bool insert(int data);
  bool remove(int data);
  bool search(int data);
  bool isEmpty();
  std::string inOrderTraversal();
  std::string preOrderTraversal();
  std::string postOrderTraversal();
  //Methods
  bool hasPathSum(int sum);
  std::vector<std::vector<int>> levelOrder();
  void connect_perfect_tree();

private:
  Node* root;
  bool insert(Node* &root, int data);
  Node* remove(Node* &root, int data, bool &removed);
  Node* findMax(Node* root);
  void destroy(Node*& root);
  bool search(Node* root, int data);
  void inOrderTraversal(Node* root, std::string &builder);
  void preOrderTraversal(Node* root, std::string &builder);
  void postOrderTraversal(Node* root, std::string &builder);

  //Methods
  bool hasPathSum(Node* root, int target, int current_sum);
  void connect_perfect_tree(Node* root, Node* ll);
};

#endif
