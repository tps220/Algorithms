#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> curr;
        createSets(result, curr, nums, 0);
        result.push_back(vector<int>());
        return result;
    }

private:
    void createSets(vector<vector<int>> &sets, vector<int> &curr, vector<int> &nums, int starting_index) {
        for (int i = starting_index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            sets.push_back(curr);
            createSets(sets, curr, nums, i + 1);
            curr.pop_back();
        }
    }
};
