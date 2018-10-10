#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequeny(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int element: nums) {
            map[element]++;
        }
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        for (auto it = map.begin(); it != map.end(); it++) {
            buckets[it -> second].push_back(it -> first);
        }
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int j = buckets[i].size() - 1; j >= 0; j--) {
                result.push_back(buckets[i][j]);
                if (k == result.size()) {
                    return result;
                }
            }
        }
        return result;
    }
};
