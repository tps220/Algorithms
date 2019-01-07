#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    if (nums.size() == 0) {
      return 0;
    }
    int end = nums.size() - 1;
    updateEnd(nums, end, val);
    for (int i = 0; i < end && nums.size(); i++) {
      if (nums[i] == val) {
        swap(nums[i], nums[end]);
        end--;
        updateEnd(nums, end, val);
      }
    }
    return end + 1;
  }
private:
  void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
  }
  void updateEnd(vector<int> &nums, int&end, int val) {
    while (end >= 0 && nums[end] == val) {
      end--;
    }
  }
};
