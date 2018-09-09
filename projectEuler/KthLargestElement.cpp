#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        k--;
        int hi = nums.size() - 1, lo = 0;
        for(;;) {
            int idx = partition(nums, lo, hi);
            if (idx > k) {
                hi = idx - 1;
            }
            else if (idx < k) {
                lo = idx + 1;
            }
            else {
                break;
            }
        }
        return nums[k];
    }
private:
    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[lo];
        int left = lo + 1;
        int right = hi;
        while (left <= right) {
            if (nums[left] < pivot && nums[right] > pivot) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
            if (nums[left] >= pivot) {
                left++;
            }
            if (nums[right] <= pivot) {
                right--;
            }
        }
        swap(nums[lo], nums[right]);
        return right; 
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
