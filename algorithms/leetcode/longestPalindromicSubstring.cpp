#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return s;
        }
        int idx = 0;
        int max_length = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            int odd = isPalindrome(s, i, i);
            int even = isPalindrome(s, i, i + 1);
            int result = odd;
            if (even > odd) {
                result = even;
            }
            if (result > max_length) {
                idx = i - result / 2;
                max_length = result;
            }
        }
        return s.substr(idx, max_length + 1);
    }
private:
    int isPalindrome(string &s, int left, int right) {
        if (s[left] != s[right]) {
            return -1;
        }
        left--;
        right++;
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        return right - left - 2;
    }
};
