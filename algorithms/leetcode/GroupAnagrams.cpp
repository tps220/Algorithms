#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string sorted = countingSort(str);
            map[sorted].push_back(str);
        }
        vector<vector<string>> arr;
        for (auto it = map.begin(); it != map.end(); it++) {
            arr.push_back(it -> second);
        }
        return arr;
    }
private:
    string countingSort(string str) {
        int map[26] = {};
        for (int i = 0; i < str.size(); i++) {
            map[str[i] - 'a']++;
        }

        int replace = 0;
        for (int i = 0; i < 26; i++) {
            while (map[i] > 0) {
                str[replace] = 'a' + i;
                replace++;
                map[i]--;
            }
        }
        return str;
    }    
};
