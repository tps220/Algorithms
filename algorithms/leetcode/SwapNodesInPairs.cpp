#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head -> next == NULL) {
      return head;
    }
    ListNode* header = head;
    ListNode* footer = head -> next;
    ListNode* old_duo = NULL;
    while (header && footer) {
      //1
      header -> next = footer -> next;
      //2
      footer -> next = header;
      //3 Base case included
      if (old_duo) {
        old_duo -> next = footer;
      }
      else {
        head = footer;
      }
      //4 The list now looks like old_duo -> footer -> header ->
      if (header -> next && header -> next -> next) {
        old_duo = header;
        header = header -> next;
        footer = header -> next;
      }
      else {
        break;
      }
    }
    return head;
  }
};
