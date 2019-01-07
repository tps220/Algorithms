#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int> &nums) {
        vector< vector<int> > output;
        combinations(output, nums, 0);
        return output;
    }
private:
    void combinations(vector< vector<int> > &sets, vector<int> &nums, size_t starting_index) {
        if (starting_index == nums.size()) {
            sets.push_back(nums);
            return;
        }
        for (size_t i = starting_index; i < nums.size(); i++) {
            swap(nums[i], nums[starting_index]);
            combinations(sets, nums, starting_index + 1);
            swap(nums[i], nums[starting_index]);
        }
        return;
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
