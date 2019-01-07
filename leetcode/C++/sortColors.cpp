#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int zero_count = 0;
        int one_count = 0;
        int two_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            switch(nums[i]) {
                case 0:
                    zero_count++;
                    break;
                case 1:
                    one_count++;
                    break;
                case 2:
                    two_count++;
                    break;
            }
        }
        
        int counter = 0;
        while(zero_count || one_count || two_count) {
            if (zero_count) {
                nums[counter] = 0;
                zero_count--;
            }
            else if (one_count) {
                nums[counter] = 1;
                one_count--;
            }
            else {
                nums[counter] = 2;
                two_count--;
            }
            counter++;
        }
    }
};
