#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        if (arr.size() == 0) {
            return -1;
        }

        int slow = arr[0];
        int runner = arr[0];
        do {
            slow = arr[slow];
            runner = arr[arr[runner]];
        } while(slow != runner);

        slow = arr[0];
        while (slow != runner) {
            slow = arr[slow];
            runner = arr[runner];
        }
        return slow;
    }
    int findDuplicate2(vector<int> &arr) {
        unordered_set<int> map;
        for (int i = 0; i < arr.size(); i++) {
            if (map.find(arr[i]) != map.end()) {
                return arr[i];
            }
            map.insert(arr[i]);
        }
        return -1;
    }
};
