#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> dp(nums.size(), 1);
        int maxval = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    maxval = max(maxval, dp[i]);
                }
            }
        }
        return maxval;
    }
private:
    int max(const int a, const int b) {
        if (a > b) {
            return a;
        }
        return b;
    }
};
