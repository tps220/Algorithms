#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


class Codec {
public:
    string serialize(TreeNode *root) {
        if (root == NULL) {
            return "";
        }
        //Initalization
        queue<TreeNode*> q;
        q.push(root);
        string data = to_string(root -> val) + ",";
        
        //Begin at root and traverse down in a BFS approach
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node -> left) {
                data.append(to_string(node -> left -> val) + ",");
                q.push(node -> left);
            } 
            else {
                data.append("n,");
            }
            if (node -> right) {
                data.append(to_string(node -> right -> val) + ",");
                q.push(node -> right);
            }
            else {
                data.append("n,");
            }
        }
        return data;
    }
    
    TreeNode* deserialize(string data) {
        //Initialization
        int buffer = 0;
        int current_num = 0;
        if (nextInteger(data, buffer, current_num) == false) {
            return NULL;
        }
        TreeNode* root = new TreeNode(current_num);
        queue<TreeNode*> q;
        q.push(root);

        while (buffer < data.length()) {
            TreeNode* node = q.front();
            q.pop();
            if (nextInteger(data, buffer, current_num)) {
                node -> left = new TreeNode(current_num);
                q.push(node -> left);
            }
            if (nextInteger(data, buffer, current_num)) {
                node -> right = new TreeNode(current_num);
                q.push(node -> right);
            } 
        }
        return root;
    }
private:
    bool nextInteger(string &data, int &buffer, int& number) {
       if (buffer >= data.length()) {
           return false;
       } 
       else if (data[buffer] == 'n') {
           buffer = buffer + 2;
           return false; 
       }
       number = 0;
       int multiplier = 1;
       if (data[buffer] == '-') {
           multiplier = -1;
           buffer++;
       }
       while (buffer < data.length() && data[buffer] != ',') {
            number = number * 10 + data[buffer] - '0';
            buffer++;
       }
       buffer++;
       number *= multiplier;
       return true;
    }
};
