#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int cut = 1; cut <= size; cut++) {
            for (int left = 1; left <= size - cut + 1; left++) {
                int right = left + cut - 1;
                for (int k = left; k <= right; k++) {
                    dp[left][right]= max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        return dp[1][size];
    }
};
