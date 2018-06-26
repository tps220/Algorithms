#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int max_length = 0;
        stack<int> indexes;
        int last = -1;
        for (int i = 0; i < s.length(); i++) {
            int ch = s[i];
            //Case 1, '(' open bracket
            if (s[i] == '(') {
                indexes.push(i);
            }
            //Case 2, '(' clsoe bracket which means theres an oppurtunity
            //for valid pranetheses if the stack size > 0
            else if (indexes.size() > 0) {
                indexes.pop(); 
                int len;
                //Two scenarios to find the length of the current sequence
                //Case 1: Reached the end of the stack, and therefore have a sequence of valid
                //parentheses, if there was a valid sequence right before the current one, 
                //then we account for that by using the last variable
                if (indexes.size() == 0) {
                    len = i - last;
                }
                //Case 2:
                //Compare the current index to the last '(' brackets
                //position that doesnt have a closing bracket, which indicates the starting
                //position of the current sequence - 1.
                else {
                    len = i - indexes.top();
                }
                //Compare current length to max length, and update if needed
                if (len > max_length) {
                    max_length = len;
                }
            }
            //if the index is empty, then we have
            //an invalid closing brace and need to
            //update the last variable to the current position
            else {
                last = i;
            }
        }
        return max_length;
    }
};
