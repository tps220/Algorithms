#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) { 
        return isValidBST(root, NULL, NULL);
    }
private:
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) {
            return true;
        }
        else if (min && root -> val <= min -> val) {
            return false;
        }
        else if (max && root -> val >= max -> val) {
            return false;
        }
        return isValidBST(root -> left, min, root) && isValidBST(root -> right, root, max);
    }
};
