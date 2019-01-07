#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int min = nums.size();
        int max = -1;
        binarySearch(nums, min, max, target, 0, nums.size() - 1);
        if (max == -1) {
            return vector<int>(2, -1);
        }
        vector<int> result;
        result.push_back(min);
        result.push_back(max);
        return result;
    }
private:
    void binarySearch(vector<int>& nums, int &min, int &max, int &target, int left, int right) {
        if (left <= right) {
            int middle = (left + right) / 2;
            if (target > nums[middle]) {
                return binarySearch(nums, min, max, target, middle + 1, right);
            }
            else if (target < nums[middle]) {
                return binarySearch(nums, min, max, target, left, middle - 1);
            }
            else {
                if (middle < min) {
                    min = middle;
                    binarySearch(nums, min, max, target, left, middle - 1);
                }
                if (middle > max) {
                    max = middle;
                    binarySearch(nums, min, max, target, middle + 1, right);
                }
            }
        }
    }
};
