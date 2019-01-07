#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP

#include "BinarySearchTree.hpp"
#include <sstream>
#include <queue>

BinarySearchTree::BinarySearchTree() {
  this -> root = NULL;
}

BinarySearchTree::BinarySearchTree(int data) {
  this -> root = new Node(data);
}

BinarySearchTree::BinarySearchTree(std::vector<int> data) {
  for (size_t i = 0; i < data.size(); i++) {
    insert(data[i]);
  }
}

BinarySearchTree::~BinarySearchTree() {
  destroy(root);
}

void BinarySearchTree::destroy(Node* &root) {
  if (root == NULL) {
    return;
  }
  destroy(root -> left);
  destroy(root -> right);
  delete root;
}

bool BinarySearchTree::insert(int data) {
  return insert(root, data);
}

bool BinarySearchTree::insert(Node* &root, int data) {
  if (root == NULL) {
    root = new Node(data);
    return true;
  }
  else if (data > root -> getData()) {
    return insert(root -> right, data);
  }
  else if (data < root -> getData()) {
    return insert(root -> left, data);
  }
  return false;
}

bool BinarySearchTree::remove(int data) {
  bool removed = false;
  root = remove(root, data, removed);
  return removed;
}

Node* BinarySearchTree::findMax(Node* root) {
  if (root -> right == NULL) {
    return root;
  }
  return findMax(root -> right);
}

Node* BinarySearchTree::remove(Node* &root, int data, bool &removed) {
  if (root == NULL) {
    return NULL;
  }
  else if (data > root -> getData()) {
    root -> right = remove(root -> right, data, removed);
  }
  else if (data < root -> getData()) {
    root -> left = remove(root -> left, data, removed);
  }
  else if (root -> right == NULL && root -> left == NULL) {
      delete root;
      removed = true;
      return NULL;
  }
  else if (root -> left == NULL) {
    Node* temp = root -> right;
    delete root;
    removed = true;
    return temp;
  }
  else if (root -> right == NULL) {
    Node* temp = root -> left;
    delete root;
    removed = true;
    return temp;
  }
  else {
    Node* temp = findMax(root -> left);
    root -> setData(temp -> getData());
    removed = true;
    return remove(root -> left, data, removed);
  }
  return root;
}

bool BinarySearchTree::search(int data) {
  return search(root, data);
}

bool BinarySearchTree::search(Node* root, int data) {
  if (root == NULL) {
    return false;
  }
  else if (data > root -> getData()) {
    return search(root -> right, data);
  }
  else if (data < root -> getData()) {
    return search(root -> left, data);
  }
  return true;
}

bool BinarySearchTree::isEmpty() {
  return root == NULL;
}

std::string BinarySearchTree::preOrderTraversal() {
  std::string builder = "";
  preOrderTraversal(root, builder);
  return builder;
}

std::string BinarySearchTree::postOrderTraversal() {
  std::string builder = "";
  postOrderTraversal(root, builder);
  return builder;
}

std::string BinarySearchTree::inOrderTraversal() {
  std::string builder = "";
  inOrderTraversal(root, builder);
  return builder;
}

void BinarySearchTree::preOrderTraversal(Node* root, std::string &builder) {
  if (root == NULL) {
    return;
  }
  std::ostringstream ss;
  ss << root -> getData() << " ";
  builder.append(ss.str());
  preOrderTraversal(root -> left, builder);
  preOrderTraversal(root -> right, builder);
}

void BinarySearchTree::postOrderTraversal(Node* root, std::string &builder) {
  if (root == NULL) {
    return;
  }
  postOrderTraversal(root -> left, builder);
  postOrderTraversal(root -> right, builder);
  std::ostringstream ss;
  ss << root -> getData() << " ";
  builder.append(ss.str());
}

void BinarySearchTree::inOrderTraversal(Node* root, std::string &builder) {
  if (root == NULL) {
    return;
  }
  inOrderTraversal(root -> left, builder);
  std::ostringstream ss;
  ss << root -> getData() << " ";
  builder.append(ss.str());
  inOrderTraversal(root -> right, builder);
}

bool BinarySearchTree::hasPathSum(int sum) {
  return hasPathSum(root, sum, 0);
}

bool BinarySearchTree::hasPathSum(Node* root, int target, int current_sum) {
  if (root == NULL) {
    return false;
  }
  else if (target == current_sum) {
    return true;
  }
  return hasPathSum(root -> left, target, current_sum + root ->getData()) ||
         hasPathSum(root -> right, target, current_sum + root -> getData());
}


std::vector<std::vector<int>> BinarySearchTree::levelOrder() {
  //set will store the neighbors at each level
  std::vector<std::vector<int>> set;
  if (root == NULL) {
    return set;
  }
  //current working group
  std::queue<Node*> queue;
  queue.push(root);
  set.push_back(std::vector<int>());
  size_t idx = 0;
  //next working group at the next level
  std::queue<Node*> next;
  while (queue.size() > 0) {
    Node* front = queue.front();
    if (front -> left) {
      next.push(front -> left);
    }
    if (front -> right) {
      next.push(front -> right);
    }
    set[idx].push_back(front -> getData());
    queue.pop();
    if (queue.size() == 0) {
      //begin next working set to store
      set.push_back(std::vector<int>());
      idx++;
      //go to the next working set, if there is one
      queue.swap(next);
    }
  }
  set.pop_back();
  return set;
}


void BinarySearchTree::connect_perfect_tree() {
  if (root == NULL) {
    return;
  }
  root -> setNext(NULL);
  return connect_perfect_tree(root, root);
}

void BinarySearchTree::connect_perfect_tree(Node* root, Node* ll) {
  if (root -> left == NULL) {
    return;
  }
  ll -> left -> setNext(ll -> right);
  if (ll -> getNext() != NULL) {
    ll -> right -> setNext(ll -> getNext() -> left);
    return connect_perfect_tree(root, ll -> getNext());
  }
  ll -> right -> setNext(NULL);
  return connect_perfect_tree(root -> left, root -> left);
}

void BinarySearchTree::connect_tree() {
  if (root == NULL) {
    return;
  }
  return connect_tree(root, root);
}

void BinarySearchTree::connect_tree(Node* last_join, Node* ll) {
  //Base case, done linking
  if (last_join == NULL) {
    return;
  }
  //Need to find the next level branch
  else if (ll == NULL) {
    Node* link = NULL;
    while (last_join) {
      if (last_join -> left) {
        link = last_join -> left;
        break;
      }
      else if (last_join -> right) {
        link = last_join -> right;
        break;
      }
      last_join = last_join -> getNext();
    }
    return connect_tree(link, link);
  }
  //Condition 1: Left and Right Children Present
  if (ll -> left && ll -> right) {
    ll -> left -> setNext(ll -> right);
    Node* runner = ll;
    while (runner -> getNext()) {
      if (runner -> getNext() -> left) {
        ll -> right -> setNext(runner -> getNext() -> left);
        break;
      }
      else if (runner -> getNext() -> right) {
        ll -> right -> setNext(runner -> getNext() -> right);
        break;
      }
      runner = runner -> getNext();
    }
    //if no nodes left to connect, set to null
    if (runner -> getNext() == NULL) {
      ll -> right -> setNext(NULL);
    }
    //return the next node with a child to be set
    return connect_tree(last_join, runner -> getNext());
  }
  //Condition 2: Only Left or Right Child
  Node* child;
  if (ll -> left) {
    child = ll -> left;
  }
  else if (ll -> right) {
    child = ll -> right;
  }
  //or no children so go to the next node
  else {
    return connect_tree(last_join, ll -> getNext());
  }
  Node* runner = ll;
  while (runner -> getNext()) {
    if (runner -> getNext() -> left) {
      child -> setNext(runner -> getNext() -> left);
      break;
    }
    else if (runner -> getNext() -> right) {
      child -> setNext(runner -> getNext() -> right);
      break;
    }
    runner = runner -> getNext();
  }
  if (runner -> getNext() == NULL) {
    child-> setNext(NULL);
  }
  return connect_tree(last_join, runner -> getNext());
}




#endif
