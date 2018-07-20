#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : next(NULL), val(x) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return false;
        }
        ListNode* root = head;
        ListNode* runner = head -> next;
        while (runner != NULL && runner -> next != NULL) {
            if (root == runner) {
                return true;
            }
            root = root -> next;
            runner = runner -> next -> next;
        }
        return false;
    }
};
