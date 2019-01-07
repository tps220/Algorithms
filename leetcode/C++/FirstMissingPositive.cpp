#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &original) {
        vector<int> nums(original);
        int max = (int)nums.size();
        for (int i = 0; i < max; i++) {
            if (nums[i] <= 0) {
                nums[i] = max + 1;
            }
        }

        int found = 0;
        for (int i = 0; i < max; i++) {
            if (abs(nums[i]) <= max) {
                if (nums[abs(nums[i]) - 1] > 0) {
                    nums[abs(nums[i]) - 1] *= -1;
                    found++;
                }
            }
        }

        if (found < max) {
            for (int i = 0; i < max; i++) {
                if (nums[i] > 0) {
                    return i + 1;
                }
            }
        }
        return max + 1;
        
    }
};
