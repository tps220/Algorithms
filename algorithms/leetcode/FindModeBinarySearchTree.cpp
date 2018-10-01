#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        //if an empty tree, then return an empty array
        if (root == NULL) {
            return vector<int>();
        }
        
        vector<int> modes;
        int currentCount = 0;
        int maxCount = 1;
        int previousNode = 0;
        findModeHelper(root, modes, currentCount, maxCount, previousNode);
        return modes;
    }
private:
    void findModeHelper(TreeNode* root, vector<int> &modes, int &currentCount, int &maxCount, int& previousNode) {
        if (root == NULL) {
            return;
        }

        findModeHelper(root -> left, modes, currentCount, maxCount, previousNode);
        if (root -> val == previousNode && currentCount != 0) {
            currentCount++;
        }
        else {
            currentCount = 1;
        }
        if (currentCount == maxCount) {
            modes.push_back(root -> val);
        }
        else if (currentCount > maxCount) {
            modes.clear();
            modes.push_back(root -> val);
            maxCount = currentCount;
        }
        previousNode = root -> val;

        findModeHelper(root -> right, modes, currentCount, maxCount, previousNode);
    }
};
