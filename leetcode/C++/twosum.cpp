#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++) {
            //Current value in list
            int current_num = nums[i];
            //If we find in the map the compliment of an old value
            //equals the current value, then we have a pair that
            //matches our target
            if (map.find(current_num) != map.end()) {
                vector<int> retval;
                retval.push_back(map[current_num]);
                retval.push_back(i);
                return retval;
            }
            map.insert(make_pair<int, int>(target - current_num, i));
        }
        return vector<int>(2, -1);
    }
};
