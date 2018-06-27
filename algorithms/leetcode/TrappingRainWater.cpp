#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> map;
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!map.empty() && height[i] > height[map.top()]) {
                int top = map.top();
                map.pop();
                if (map.empty()) {
                    break;
                }
                sum += (i - top - 1) * (min(height[i], height[map.top()]) - height[top]);
            }
            map.push(i);
        }
    }
private:
    int min(int &a, int &b) {
        if (a > b) {
            return a;
        }
        return b;
    }
};
