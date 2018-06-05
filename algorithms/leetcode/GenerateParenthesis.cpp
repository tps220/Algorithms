#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    createSet(result, "", n, n);
    return result;
  }
private:
  void createSet(vector<string> &set, string buffer, int left, int right) {
    if (right == 0) {
      set.push_back(buffer);
      return;
    }
    if (left > 0) {
      createSet(set, buffer + "(", left - 1, right);
    }
    if (right > left && right > 0) {
      createSet(set, buffer + ")", left, right - 1);
    }
  }
};
