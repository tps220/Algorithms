#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : left(NULL), right(NULL), val(x) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetricHelper(root -> left, root -> right);
    }
private:
    bool isSymmetricHelper(TreeNode* l, TreeNode* r) {
        if (!l && !r) {
            return true;
        }
        else if (!l || !r) {
            return false;
        }
        else if (l -> val != r -> val) {
            return false;
        }
        return isSymmetricHelper(l -> left, r -> right) && isSymmetricHelper(l -> right, r -> left);
    }
};
