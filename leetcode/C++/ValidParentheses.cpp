#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> map;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
        map.push(s[i]);
      }
      else {
        if (map.size() == 0) {
          return false;
        }
        char ch = map.top();
        if (s[i] == '}' && ch != '{') {
          return false;
        }
        else if (s[i] == ')' && ch != '(') {
          return false;
        }
        else if (s[i] == ']' && ch != '[') {
          return false;
        }
        map.pop();
      }
    }
    return map.size() == 0;
  }
};
