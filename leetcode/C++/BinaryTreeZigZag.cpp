#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {}
};

enum Direction {
    LEFT,
    RIGHT
};

class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > retval;
        if (root == NULL) {
            return retval;
        }
        retval.push_back(vector<int>());
        deque<TreeNode*> curr;
        deque<TreeNode*> next;
        Direction direction = RIGHT;
        curr.push_back(root);
        while (!curr.empty()) {
           TreeNode* element = curr.back();
           curr.pop_back();
           retval[retval.size() - 1].push_back(element -> val);
           cout << element -> val << endl;
           if (direction == RIGHT) {
               if (element -> left != NULL) { next.push_back(element -> left); }
               if (element -> right != NULL) { next.push_back(element -> right); }
           }
           else {
               if (element -> right != NULL) { next.push_back(element -> right); }
               if (element -> left != NULL) { next.push_back(element -> left); }
           }
           if (curr.empty()) {
               if (next.empty()) {
                   break;
               }
               curr.swap(next);
               swapDirection(direction);
               retval.push_back(vector<int>());
           }
        }
        return retval;
    }
private:
    void swapDirection(Direction &direction) {
        if (direction == RIGHT) {
            direction = LEFT;
            return;
        }
        direction = RIGHT;
    }
};
