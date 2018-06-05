#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* root) {
    if (root == NULL) {
      return root;
    }
    else if (root -> next == NULL) {
      return root;
    }
    ListNode* base = NULL;
    ListNode* header = root;
    ListNode* footer = root -> next;
    while (footer != NULL) {
      header -> next = footer -> next;
      footer -> next = header;
      if (base != NULL) {
        base -> next = footer;
      }
      if (header -> next == NULL || header -> next -> next == NULL) {
        return root;
      }
      base = header;
      header = header -> next;
      footer = header -> next -> next;
    }
    return root;
  }
};
