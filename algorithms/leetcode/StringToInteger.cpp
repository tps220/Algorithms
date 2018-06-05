#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      int result = 0;
      //Cleanup possible whitespace
      int i = 0;
      int length = str.length();
      while (i < length && str[i] == ' ') {
        i++;
      }
      if (i == length) {
        return 0;
      }

      int sign = 1;
      //Check for sign
      if (str[i] == '-') {
         sign = -1;
         i++;
      }
      else if (str[i] == '+') {
        i++;
      }
      //Begin calculations
      while (i < length) {
        //validate the digit
        if (str[i] > '9' || str[i] < '0') {
          break;
        }
        //Check for overflow
        //case 1: if negative
        if (sign == -1) {
          int difference = result - INT_MIN / 10;
          if (difference < 0) {
            return INT_MIN;
          }
          else if (difference == 0 && str[i] - '0' >= 8) {
            return INT_MIN;
          }
        }
        //case 2: positive
        else {
          int difference = result - INT_MAX / 10;
          if (difference > 0) {
            return INT_MAX;
          }
          else if (difference == 0 && str[i] - '0' >= 7) {
            return INT_MAX;
          }
        }
        result = result * 10 + (str[i] - '0') * sign;
        i++;
      }
      return result;
    }
};
