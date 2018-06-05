#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.length() == 0) {
        return result;
    }
    vector<string> map(10, "");
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";

    string buffer = "";
    createCombinations(map, result, digits, 0, buffer);
    return result;
  }
private:
  void createCombinations(vector<string> &map, vector<string> &result, string digits, int idx, string &buffer) {
    if (idx == digits.length()) {
      result.push_back(buffer);
      return;
    }
    for (int i = 0; i < map[digits[idx] - '0'].length(); i++) {
      char ch = map[digits[idx] - '0'][i];
      buffer.push_back(ch);
      createCombinations(map, result, digits, idx + 1, buffer);
      buffer.pop_back();
    }
  }
};
