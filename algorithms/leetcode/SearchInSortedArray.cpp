#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>&nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int middle = (left + right) / 2;
        if (nums[middle] == target) {
            return middle;
        }
        //in an ascending subarray, do regular binary search
        else if (nums[left] <= nums[right]) {
            if (target > nums[middle]) {
                return binarySearch(nums, target, middle + 1, right);
            }
            return binarySearch(nums, target, left, middle - 1);
        }
        //still encapsulating a rotated array
        if (target >= nums[left] && nums[middle] >= nums[left] && target < nums[middle]) {
            return binarySearch(nums, target, left, middle - 1);
        }
        else if (target >= nums[left] && nums[middle] < nums[left] && target >= nums[middle]) {
            return binarySearch(nums, target, left, middle - 1);
        }
        else if (target < nums[left] && nums[middle] < nums[left] && target < nums[middle]) {
            return binarySearch(nums, target, left, middle - 1);
        }
        return binarySearch(nums, target, middle + 1, right);
    }
};
