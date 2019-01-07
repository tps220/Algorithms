#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        for(;;) {
            //check if equal at any point, could either both be null
            //or could both be a valid intersection point
            if (a == b) {
                return a;
            }

            //properly move to next list node
            if (a == NULL) {
                a = headB;
            }
            else {
                a = a -> next;
            }

            if (b == NULL) {
                b = headA;
            }
            else {
                b = b -> next;
            }
        }

        return NULL;
    }
};
