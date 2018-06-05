#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *merged_list = new ListNode(0);
    ListNode *runner = merged_list;
    while (l1 && l2) {
      if (l1 -> val < l2 -> val) {
        runner -> next = l1;
        l1 = l1 -> next;
      }
      else {
        runner -> next = l2;
        l2 = l2 -> next;
      }
      runner = runner -> next;
    }
    if (l1) {
      runner -> next = l1;
    }
    else if (l2) {
      runner -> next = l2;
    }
    ListNode *temp = merged_list;
    merged_list = merged_list -> next;
    delete temp;
    return merged_list;
  }
};
