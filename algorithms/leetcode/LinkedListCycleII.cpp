#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* root = head;
        ListNode* runner = head;
        while(runner != NULL && runner -> next != NULL) {
            runner = runner -> next -> next;
            root = root -> next;
            if (runner == root) {
                //detected a loop, determine the start of the loop
                root = head;
                while (root != runner) {
                    root = root -> next;
                    runner = runner -> next;
                }
                return root;
            }
        }
        return NULL;
    }
};
