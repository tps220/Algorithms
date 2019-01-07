#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int maxRectangle = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                }
                else {
                    height[j]++;
                }
            }
            maxRectangle = max(maxRectangle, largestRectangleArea(height));
        }
    }
 private:
    int largestRectangleArea(vector<int> &height) {
        
        int maxRectangle = 0;
        vector<int> stack;
        height.push_back(0);
        for (int i = 0; i < height.size(); i++) {
            while(stack.size() > 0 && height[stack.back()] >= height[i]) {
                int h = height[stack.back()];
                stack.pop_back();
                int x = -1;
                if (stack.size() > 0) {
                    x = stack.back();
                }
                int dx = i - x - 1;
                if (dx * h > maxRectangle) {
                    maxRectangle = dx * h;
                }
            } 
            stack.push_back(i);
        }
        height.pop_back();
        return maxRectangle;
    }
};
