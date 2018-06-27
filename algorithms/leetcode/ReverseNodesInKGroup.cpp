#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* ll, int k) {
        if (ll == NULL || k <= 1) {
            return ll;
        }
        else if (ll -> next == NULL) {
            return ll;
        }
        ListNode* base = NULL;
        ListNode* head = ll;
        ListNode* previous = NULL;
        ListNode* curr = ll;
        ListNode* runner = ll -> next;
        ListNode* tail = ll;
        int counter = 1;
        for(;;) {
            for (int i = 1; i < k; i++) {
                if (tail -> next == NULL) {
                    return ll;
                }
                tail = tail -> next;
            }
            for (int i = 0; i < k; i++) {
                curr -> next = previous;
                previous = curr;
                curr = runner;
                if (i != k - 1) {
                    runner = runner -> next;
                }
            }
            head -> next = curr;
            if (base != NULL) {
                base -> next = tail;
            }
            else {
                ll = tail;
            }
            
            base = head;
            head = head -> next;
            if (head == NULL || head -> next == NULL) {
                return ll;
            }
            previous = NULL;
            curr = head;
            runner = head -> next;
            tail = head;
        }
        return ll;
    }
};
