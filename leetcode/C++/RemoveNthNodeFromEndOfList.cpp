#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    return removeHelper(head, n);
  }
private:
  ListNode* removeHelper(ListNode* head, int& n) {
    if (head == NULL) {
      return NULL;
    }
    head -> next = removeHelper(head -> next, n);
    n--;
    if (n == 0) {
      ListNode* temp = head -> next;
      delete head;
      return temp;
    }
    return head;
  }
};
