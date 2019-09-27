#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//a + b + c + d = target
// c + d = target - a - b

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    //Return value to store the 4-tuples that sum to the target
    vector<vector<int>> result;

    //iterate through all the possible 4-tuples that can sum to target
    for (int i = 0; i < (int)nums.size() - 3; i++) {
      int a = nums[i];
      //iterate through all the possible 3-tuples that can sum to target with
      //the fixed number above
      for (int j = i + 1; j < (int)nums.size() - 2; j++) {
        int b = nums[j];
        //aim represents the idea that c + d = target - a - b
        int aim = target - a - b;
        //initialize starting indexes
        int left = j + 1, right = (int)nums.size() - 1;
        //continue to decrease the window until the left and right
        //indexes overlap and start creating duplicate tuples
        while (right > left) {
          //sum reperesnts c + d
          int sum = nums[left] + nums[right];
          //if the sum is greater than the aim, then decrement the right index
          //to decrease its magnitude
          if (sum > aim) {
            right--;
          }
          //if the sum is smaller than the aim, then increment the left index
          //to increase its magnitude
          else if (sum < aim) {
            left++;
          }
          //if equal, then add to the collection and update the indexes
          else {
            //create the instance for insertion of the 4-tuple
            const int solution[4] = { nums[i], nums[j], nums[left], nums[right] };
            result.push_back(vector<int>(solution, solution + 4));
            
            //update the left and right indexes to avoid any duplicates
            while (left < right && nums[left] == solution[2]) left++;
            while (left < right && nums[right] == solution[3]) right--;
          }
        }
        while (j < nums.size() - 2 && nums[j] == nums[j + 1]) {
          j++;
        }
      }
      while (i < nums.size() - 3 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return result;
  }
};
