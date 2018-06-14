#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int> > retval;
        vector<int> current_set;
        sort(candidates.begin(), candidates.end());
        combination(retval, candidates, current_set, target, 0);
        return retval;
    }
private:
    void combination(vector< vector<int> >& sets, vector<int>& candidates, vector<int>& curr, int target, size_t starting_index) {
        if (target < 0) {
            return;
        }
        else if (target == 0) {
            sets.push_back(curr);
            return;
        }

        size_t i = starting_index;
        while (i < candidates.size()) {
            curr.push_back(candidates[i]);
            target -= curr.back();
            combination(sets, candidates, curr, target, i + 1);
            int last = curr.back();
            target += last;
            curr.pop_back();
            i++;
            while (i < candidates.size() && candidates[i] == last) {
                i++;
            }
        }
        return;
    }
};
