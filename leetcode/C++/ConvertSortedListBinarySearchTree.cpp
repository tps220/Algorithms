#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* runner = head;
        int size = 1;
        while (runner -> next != NULL) {
            runner = runner -> next;
            size++;
        }
        runner = head;
        return sortedListToBST(runner, 0, size - 1);
    }

    TreeNode* sortedListToBST(ListNode*& runner, int left, int right) {
        if (left > right) {
            return NULL;
        }
        TreeNode* tree = new TreeNode(0);
        int mid = (left + right) / 2;
        
        tree -> left = sortedListToBST(runner, left, mid - 1);
        tree -> val = runner -> val;
        runner = runner -> next;
        tree -> right = sortedListToBST(runner, mid + 1, right);

        return tree;
    }

    TreeNode* sortedListToBST2(ListNode* head) {
        ListNode *left = head, *right = NULL;
        return sortedListToBSTHelper2(left, right);
    }
private:
    TreeNode* sortedListToBSTHelper2(ListNode* left, ListNode* right) {
        if (left == right) {
            return NULL;
        }
        ListNode* runner = left;
        ListNode* slow = left;
        while (runner != right && runner -> next != right) {
            runner = runner -> next -> next;
            slow = slow -> next;
        }
        TreeNode* tree = new TreeNode(slow -> val);
        tree -> left = sortedListToBSTHelper2(left, slow);
        tree -> right = sortedListToBSTHelper2(slow -> next, right);
        return tree;
    }
};
