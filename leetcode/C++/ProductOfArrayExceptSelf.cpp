#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 0);
        int left_mult_buffer = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] = left_mult_buffer;
            left_mult_buffer *= nums[i];
        }
        int right_mult_buffer = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= right_mult_buffer;
            right_mult_buffer *= nums[i];
        }
        return output;
    }
};
