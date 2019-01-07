#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    string num = to_string(x);
    int length = num.length();
    for (int i = 0; i <= length / 2; i++) {
      if (num[i] != num[length - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};
