#include "BinarySearchTree.hpp"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

#define TEST_SIZE 18
#define RANGE_SIZE 102

vector<int> parseInts(string inorder) {
  vector<int> retval;
  size_t i = 0;
  int curr = 0;
  while (i < inorder.length()) {
    if (inorder[i] == ' ') {
      retval.push_back(curr);
      curr = 0;
    }
    else {
      curr = curr * 10 + inorder[i] - '0';
    }
    i++;
  }
  return retval;
}

int main(int argc, char** argv) {
  BinarySearchTree *tree = new BinarySearchTree();
  vector<int> data_set;

  //create test set
  unordered_set<int> insertion;
  for (int i = 0; i < TEST_SIZE; i++) {
    insertion.insert(rand() % RANGE_SIZE);
  }
  for (unordered_set<int>::iterator it = insertion.begin(); it != insertion.end(); it++) {
    data_set.push_back(*it);
  }
  insertion.clear();


  //Test Insert
  for (size_t i = 0; i < data_set.size(); i++) {
    tree -> insert(data_set[i]);
  }
  string inorder = tree -> inOrderTraversal();
  cout << inorder << endl;
  vector<int> parser = parseInts(inorder);
  vector<int> sorted = data_set;
  sort(sorted.begin(), sorted.end());
  for (size_t i = 0; i < data_set.size(); i++) {
    if (parser[i] != sorted[i]) {
      cout << "INSERT FAILED" << endl;
      return 1;
    }
  }
  cout << "INSERT PASSED" << endl;

  //Test Remove
  for (size_t i = 0; i < data_set.size() / 4; i++) {
    int random = rand() % sorted.size();
    if (random < 0) {
      continue;
    }
    int temp = sorted[random];
    sorted.erase(sorted.begin() + random);
    tree -> remove(temp);
  }
  for (size_t i = 0; i < sorted.size() / 4; i++) {
    if (parser[i] != sorted[i]) {
      cout << "DELETE FAILED" << endl;
      return 1;
    }
  }
  cout << "DELETE PASSED" << endl;

  //TEST SEARCH
  for (size_t i = 0; i < sorted.size(); i++) {
    if (!(tree -> search(sorted[i]))) {
      cout << "SEARCH FAILED" << endl;
      return 1;
    }
  }
  cout << "SEARCH PASSED" << endl;

  delete tree;



  return 0;
}
