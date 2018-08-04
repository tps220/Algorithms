#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        //empty arrays return 0 by default
        if (nums.size() == 0) {
            return 0;
        }
        //store the number of negatives seen in the current
        //sequence of numbers
        int negatives = 0;
        //store the starting index of the current sequence of numbers
        int begin = 0;
        //Base case, the max product is the first number in the array
        int max = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            //if a negative number is found, keep track for the current sequence
            if (nums[i] < 0) {
                negatives++;
            }
            //if we're at the end or the current number is equal to zero,
            //we have a possible max and therefore call the findMax function
            if (nums[i] == 0 || i == nums.size() - 1) {
                int result = findMax(nums, begin, i, negatives);
                if (result > max) {
                    max = result;
                }
                //reset variables
                begin = i + 1;
                negatives = 0;
            }
        }
        return max;
    }
private:
    int findMax(vector<int>& nums, int start, int end, int negatives) {
        //stores the product of the entire sequence
        int product = 1;
        //stores if the first negative has been found
        bool found = false;
        //stores whether a second product is needed, which will
        //only be initiated if the number of negatives is odd
        bool start_second_target = false;
        int target = 0;

        int max = nums[0];
        for (int i = start; i <= end; i++) {
            //If a negative number is found
            if (nums[i] < 0) {
                //if this is the first negatvie number found
                if (found == false) {
                    found = true;
                    //if the number of negative values is odd, keep a second count
                    if (negatives % 2 == 1) {
                        start_second_target = true;
                        target = 1;
                    }
                }
            }
            //update value(s)
            product *= nums[i];
            if (start_second_target && i != end) {
                target *= nums[i + 1];
                if (target > max) {
                    max = target;
                }
            }
            if (product > max) {
                max = product;
            }
        }
        return max;
    }
};
