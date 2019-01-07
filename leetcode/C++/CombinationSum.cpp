#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > retval;
        vector<int> curr_buffer;
        sort(candidates.begin(), candidates.end());
        combination(retval, candidates, curr_buffer, 0, target);
        return retval;
    }
private:
    void combination(vector< vector<int> > &sets, vector<int>& candidates, vector<int> &curr, size_t starting_index, int target) {
        if (starting_index == candidates.size()) {
            return;
        }
        else if (target < 0) {
            return;
        }
        else if (target == 0) {
            sets.push_back(curr);
            //since all positive integers, current set only has
            //one unique solution
            return;
        }

        for (size_t i = starting_index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            target -= curr.back();
            combination(sets, candidates, curr, i, target);
            target += curr.back();
            curr.pop_back();
        }
        return;
    }
};
