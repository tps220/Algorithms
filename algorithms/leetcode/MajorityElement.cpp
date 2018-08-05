#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0, retval = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                retval = nums[i];
            }
            if (retval == nums[i]) {
                count++;
            }
            else {
                count--;
            }
        }
        return retval;
    }
    int majorityElementAlternateSolution(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
