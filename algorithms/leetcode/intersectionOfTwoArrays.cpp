#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map;
        vector<int> intersection;
        for (int i = 0; i < nums1.size(); i++) {
            if (map.find(nums1[i]) == map.end()) {
                map[nums1[i]] = 1;
            }
            else { 
                map[nums1[i]]++;
            }
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (map.find(nums2[i]) != map.end() && map[nums2[i]] > 0) {
                map[nums2[i]]--;
                intersection.push_back(nums2[i]);
            }
        }
        return intersection;
    }
};
