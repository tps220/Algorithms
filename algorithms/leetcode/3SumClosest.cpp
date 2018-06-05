#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//a + b + c = target
//a + b = target - c

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    //if invalid input return 0
    if (nums.size() < 3) {
      return 0;
    }
    //base conidition of closest sum
    int closest = nums[0] + nums[1] + nums[2];

    //iterate through all possible 3-tuples
    for (int i = 0; i < (int)nums.size() - 2; i++) {
      //aim represents the sum we want to achieve
      int aim = target - nums[i];
      //initialize indexes
      int left = i + 1;
      int right = nums.size() - 1;
      //continue to try to narrow the window of the sum
      while (right > left) {
        int sum = nums[left] + nums[right];
        //case 1: sum is too large, must decrement right index
        //to decrease the sum
        if (sum > aim) {
          right--;
        }
        //case 2: sum is too small, must increment left index
        //to incrase the sum
        else if (sum < aim) {
          left++;
        }
        //case 3: left and right hand sides are equal, sum is obtained
        //exactly and can return the target
        else {
          return target;
        }

        //Update the closest sum
        sum += nums[i];
        if (abs(sum - target) < abs(closest - target)) {
          closest = sum;
        }
      }
      while (i < nums.size() - 2 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return closest;
  }
};
