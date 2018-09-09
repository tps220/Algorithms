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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode* lh = lowestCommonAncestor(root -> left, p, q);
        TreeNode *rh = lowestCommonAncestor(root -> right, p, q);
        
        if (lh && rh) {
            return root;
        }
        else if (lh) {
            return lh;
        }
        return rh;
    }
};
