#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.size() < k || k == 0) {
            return vector<int>();
        }
        vector<int> result;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() < i - k + 1) {
                q.pop_front();
            }
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
private:
    int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }
};
