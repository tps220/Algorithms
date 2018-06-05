#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Initialize char map
        int map[128] = {0};
        int starting_index = 0;
        int max_length = 0;
        for (int i = 0; i < s.size(); i++) {
            //any nonzero value indicates the character has been seen before,
            //so we need to update the placement
            int character = s[i];
            if (map[character] > starting_index) {
                starting_index = map[character];
            }
            else {
                int current_length = i - starting_index + 1;
                if (current_length > max_length) {
                    max_length = current_length;
                }
            }
            map[character] = i + 1;
        }
        return max_length;

    }

};
