#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int lastIndex = nums.size() - 1;
        for (int i = lastIndex; i >= 0; i--) {
            if (nums[i] + i >= lastIndex) {
                lastIndex = i;
            }
        }
        return lastIndex == 0;
    }
    bool canJump2(vector<int> &nums) {
        if (nums.size() == 0) {
            return true;
        }
        bool retval = false;
        unordered_map<int, int> map;
        dfs2(nums, 0, retval, map);
        return retval;
    }
private:
    void dfs2(vector<int> &nums, int idx, bool &retval, unordered_map<int, int> &map) {
        if (idx >= nums.size() - 1) {
            retval = true;
            return;
        }
        else if (map.find(idx) != map.end()) {
            int determined = map[idx];
            if (determined > 0 || determined < 0) {
                return;
            }
        }

        for (int i = nums[idx]; i > 0; i--) {
            dfs2(nums, idx + i, retval, map);
            if (retval == true) {
                map[idx] = 2;
            }
        }
        map[idx] = -1;
    }
};
