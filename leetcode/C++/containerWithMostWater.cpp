#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int starting_index = 0;
        int ending_index = height.size() - 1;
        while (ending_index > starting_index) {
            int area = calculateArea(starting_index, ending_index, height);
            if (area > max_area) {
                max_area = area;
            }
            if (height[starting_index] > height[ending_index]) {
                ending_index--;
            }
            else {
                starting_index++;
            }
        }
        return max_area;
    }
private:
    int calculateArea(int starting_index, int ending_index, vector<int> &height) {
        int min_height = height[starting_index];
        if (min_height > height[ending_index]) {
            min_height = height[ending_index];
        }
        return (ending_index - starting_index) * min_height;
    }
};
