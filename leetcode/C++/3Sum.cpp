#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//(a + b) + c = 0


class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    //Sort for ordered comparisons
    sort(nums.begin(), nums.end());
    //Initialize return value that stores all the sequences
    vector<vector<int>> result;

    //Iterate through all possible 3-tuples
    for (int i = 0; i < (int)nums.size() - 2; i++) {
      //Let c = nums[i]
      int target = nums[i];
      //if the current number is greater than zero, then since the array
      //has been sorted, there can not be a sum equal to zero
      if (target > 0) {
        return result;
      }
      //starting and ending indexes
      int left = i + 1, right = nums.size() - 1;
      //continually decrement the window and compare the current sum to 0
      while (right > left) {
        int sum = nums[left] + nums[right];
        //if sum is too big, that means the right needs to be decremented to
        //lower the magnitude of the sum
        if (sum + target > 0) {
          right--;
        }
        //else if the sum is too small, that means the left needs to be incremented
        //to increase the magnitude of the sume
        else if (sum + target < 0) {
          left++;
        }
        //otherwise the sum is equal to zero, and we have a candidate
        else {
          //create the vector to insert to the collection
          int l = nums[left];
          int r = nums[right];
          pushSolution(result, l, r, -target);
          
          //update positions
          while (left < right && nums[left] == l) left++;
          while (left < right && nums[right] == r) right--;
        }
      }
      while (i < (int)nums.size() - 2 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return result;
  }
private:
  void pushSolution(vector<vector<int> >&set, int a, int b, int c) {
    vector<int> vals;
    vals.push_back(a);
    vals.push_back(b);
    vals.push_back(c);
    set.push_back(vals);
  }
};
