#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //If the original input is NULL, return NULL
        //If on any recursive call the next list node is null, this means we have
        //a list length of 1 and can return
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* mid = head;
        ListNode* runner = head;
        //Get Middle
        while (runner -> next && runner -> next -> next) {
            mid = mid -> next;
            runner = runner -> next -> next;
        }
        //Record the right half of the list
        ListNode* r = mid -> next;
        //Split the list in half further
        mid -> next = NULL;
        //Merge the two halves
        ListNode* l = sortList(head);
        r = sortList(r);
        return merge(l, r);
    }
    void printList(ListNode* head) {
        ListNode* root = head;
        while (root != NULL) {
            cout << root -> val << "  ";
            root = root -> next;
        }
        cout << endl;
    }
private:
    ListNode* merge(ListNode* ll, ListNode* rr) {
        ListNode* l = ll;
        ListNode* r = rr;
        ListNode* new_list = new ListNode(0);
        ListNode* runner = new_list;
        while (l != NULL && r != NULL) {
            if (l -> val < r -> val) {
                runner -> next = l;
                l = l -> next;
            }
            else {
                runner -> next = r;
                r = r -> next;
            }
            runner = runner -> next;
        }
        if (l) {
            runner -> next = l;
        }
        else {
            runner -> next = r;
        }
        runner = new_list;
        new_list = new_list -> next;
        delete runner;
        return new_list;
    }
};



int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid number of command line arguments, provide [list of nums]" << endl;
        return 1;
    }
    ListNode* base = new ListNode(42);
    ListNode* runner = base;
    int current_num = 0;
    int idx = 0;
    while (argv[1][idx] != '\0') {
        if (argv[1][idx] == ',') {
            runner -> next = new ListNode(current_num);
            runner = runner -> next;
            current_num = 0;
        }
        else {
            current_num = current_num * 10 + argv[1][idx] - '0';
        }
        idx++;
    }
    runner -> next = new ListNode(current_num);
    
    Solution run_method;
    run_method.printList(base);
    base = run_method.sortList(base);
    run_method.printList(base);
    //deal with memory leak later, currently just debugging
}



