#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int replace = 1;
    int i = 1;
    while (i < nums.size()) {
      if (nums[i] != nums[i - 1]) {
        nums[replace] = nums[i];
        replace++;
      }
      i++;
    }
    return replace;
  }
};
