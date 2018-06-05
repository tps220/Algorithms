#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int i = 0;
    for (;;) {
      int j = 0;
      for (;;) {
        if (j == needle.length()) {
          return i;
        }
        else if (i + j >= haystack.length()) {
          return -1;
        }
        else if (haystack[i + j] != needle[j]) {
          break;
        }
        j++;
      }
      i++;
    }
  }
};
