#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int rob(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int l = 0, r = 0;
        return robHelper(root, l, r);
    }
private:
    int robHelper(TreeNode* root, int &l, int& r) {
        if (root == NULL) {
            return 0;
        }
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = robHelper(root -> left, ll, lr);
        r = robHelper(root -> right, rl, rr);
        return max(root -> val + ll + lr + rl + rr, l + r);
    }
    int robHelper2(TreeNode* root, unordered_map<TreeNode*, int> &map) {
        if (root == NULL) {
            return 0;
        }
        else if (map.find(root) != map.end()) {
            return map[root];
        }

        int val = 0;
        if (root -> left) {
            val += rob(root -> left -> left) + rob(root -> left -> right);
        }
        if (root -> right) {
            val += rob(root -> right -> left) + rob(root -> right -> right);
        }
        val = max(val + root -> val, rob(root -> left) + rob(root -> right));
        map[root] = val;
        return val;
    }
};
