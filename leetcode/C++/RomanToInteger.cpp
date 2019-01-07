#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int *nums = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case 'I':
                    nums[i] = 1;
                    break;
                case 'V':
                    nums[i] = 5;
                    break;
                case 'X':
                    nums[i] = 10;
                    break;
                case 'L':
                    nums[i] = 50;
                    break;
                case 'C':
                    nums[i] = 100;
                    break;
                case 'D':
                    nums[i] = 500;
                    break;
                case 'M':
                    nums[i] = 1000;
                    break;
            }
        }
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                sum -= nums[i];
            }
            else {
                sum += nums[i];
            }
        }
        sum += nums[s.length() - 1];
        delete nums;
        return sum;
    }

};
