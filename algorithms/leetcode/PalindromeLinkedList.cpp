#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return true;
        }

        //Find middle
        ListNode *curr = head, *runner = head;
        while (runner -> next && runner -> next -> next) {
            runner = runner -> next -> next;
            curr = curr -> next;
        }

        //reverse right half of list
        ListNode *rh = curr -> next;
        curr -> next = NULL;
        ListNode *prv = NULL;
        while (rh != NULL) {
            ListNode *nxt = rh -> next;
            rh -> next = prv;
            prv = rh;
            rh = nxt;
        }

        rh = prv;
        ListNode* lh = head;
        while (lh && rh) {
            if (rh -> val != lh -> val) {
                return false;
            }
            rh = rh -> next;
            lh = lh -> next;
        }

        return true;
    }
};
