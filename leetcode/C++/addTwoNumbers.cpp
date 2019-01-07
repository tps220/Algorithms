#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode *l2) {
        int carry = 0;
        ListNode* root = new ListNode(0);
        ListNode* runner = root;
        while (l1 || l2 || carry) {
            int digit = 0;
            if (l1) {
                digit = l1 -> val;
                l1 = l1 -> next;
            }
            if (l2) {
                digit += l2 -> val;
                l2 = l2 -> next;
            }
            digit = digit + carry;
            runner -> next = new ListNode(digit % 10);
            runner = runner -> next;
            carry = digit / 10;
        }
        runner = root;
        root = root -> next;
        delete runner;
        return root;
    }
};
