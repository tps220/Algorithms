#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*> &lists) {
    if (lists.size() == 0) {
      return NULL;
    }
    int interval = 1;
    while (interval < lists.size()) {
      for (int i = 0; i < lists.size() - interval; i += interval * 2) {
        lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
      }
      interval *= 2;
    }
    return lists[0];
  }
private:
  ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* retval = new ListNode(0);
    ListNode* runner = retval;
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
    else {
      runner -> next = l2;
    }
    runner = retval;
    retval = retval -> next;
    delete runner;
    return retval;
  }
};
