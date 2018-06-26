#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() < 0) {
            return 0;
        }
        int sum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
private:
    int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }
};
