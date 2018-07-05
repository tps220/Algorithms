#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    //using a stack
    int trap(vector<int> &height) {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                //added height = min of bounding heights on left/right - base height on bottom
                //sum up horizontal blocks one by one
                int dh = min(height[i], height[st.top()]) - height[top];
                int dw = i - st.top() - 1;
                sum += dh * dw;
            }
            st.push(i);
        }
        return sum;
    }
    //using constant space
    int trap2(vector<int> &height) {
        if (height.size() == 0) {
            return 0;
        }
        int sum = 0, left = 0, right = height.size() - 1;
        int max_left = height[left], max_right = height[right];
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] < max_left) {
                    //sum up vertical blocks one by one
                    sum += max_left - height[left];
                }
                else {
                    max_left = height[left];
                }
                left++;
            }
            else if (height[right] < max_right) {
                sum += max_right - height[right];
                right--;
            }
            else {
                max_right = height[right];
                right--;
            }
        }
        return sum;
    }
private:
    int min(int &a, int &b) {
        if (a < b) {
            return a;
        }
        return b;
    }
};
