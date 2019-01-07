#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    string result = "";


    //Find minimum length
    int length = strs[0].length();
    for (int i = 0; i < strs.size(); i++) {
      if (strs[i].length() < length) {
        length = strs[i].length();
      }
    }

    //Iterate through characters to see if common prefixes
    for (int i = 0; i < length; i++) {
      bool invalid = false;
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != strs[j - 1][i]) {
          invalid = true;
          break;
        }
      }
      if (invalid) {
        break;
      }
      cout << strs[0][i] << endl;
      result.append(1, strs[0][i]);
    }
    return result;
  }
};
