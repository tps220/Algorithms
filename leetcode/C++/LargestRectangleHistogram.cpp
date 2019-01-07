#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int largestRectangle(vector<int> &heights) {
        int maxRectangle = 0;
        heights.push_back(0);
        vector<int> index;
        for (int i = 0; i < heights.size(); i++) {
            while (index.size() > 0 && heights[index.back()] >= heights[i]) {
                int h = heights[index.back()];
                index.pop_back();

                int x = -1;
                if (index.size() > 0) {
                    x = index.back();
                }
                if (h * (i - x - 1) > maxRectangle) {
                    maxRectangle = h * (i - x - 1);
                }
            }
            index.push_back(i);
        }
        return maxRectangle;
    }
};
