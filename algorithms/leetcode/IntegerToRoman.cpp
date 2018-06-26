#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //input guaranteed between 1 and 3999, however it should work for an aribtrary number
    //and any number of 'variable changes to the number system'
    //that cause numbers to change the rule,
    //so I won't be hardcoding in the values which downgrades performane
    string intToRoman(int num) {
        const int key_mapping[7] = {1, 5, 10, 50, 100, 500, 1000};
        const char num_mapping[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string answer = "";
        string curr = "";
        int idx = 6;
        int count = 0;
        while (num > 0) {
            if (num - key_mapping[idx] < 0) {
                idx--;
                count = 0;
                answer.append(curr);
                curr.clear();
            }
            else {
                count++;
                num -= key_mapping[idx];
                curr.push_back(num_mapping[idx]);
                if (count == 4) {
                    char ch = num_mapping[idx];
                    switch(ch) {
                        case 'I':
                            if (answer.size() > 0 && answer[answer.size() - 1] == 'V') {
                                answer[answer.size() - 1] = 'I';
                                answer.push_back('X');
                            }
                            else {
                                answer.push_back('I');
                                answer.push_back('V');
                            }
                            break;
                        case 'X':
                            if (answer.size() > 0 && answer[answer.size() - 1] == 'L') {
                                answer[answer.size() - 1] = 'X';
                                answer.push_back('C');
                            }
                            else {
                                answer.push_back('X');
                                answer.push_back('L');
                            }
                            break;
                        case 'C':
                            if (answer.size() > 0 && answer[answer.size() - 1] == 'D') {
                                answer[answer.size() - 1] = 'C';
                                answer.push_back('M');
                            }
                            else {
                                answer.push_back('C');
                                answer.push_back('D');
                            }
                            break;
                    }
                    curr.clear();
                    count = 0;
                }
            }
        }
        if (num == 0) {
            answer.append(curr);
        }
        return answer;
    }
};
