#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > retval;
        sort(nums.begin(), nums.end());
        combinations(retval, nums, 0);
        return retval;
    }
private:
    void combinations(vector< vector<int> > &sets, vector<int> nums, int starting_index) {
        if (starting_index == nums.size()) {
            sets.push_back(nums);
            return;
        }
        for (int i = starting_index; i < nums.size(); i++) {
            if (i != starting_index && nums[i] == nums[i - 1]) {
                continue;
            }
            swap(nums[i], nums[starting_index]);
            combinations(sets, nums, starting_index + 1);
        }
        return;
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
