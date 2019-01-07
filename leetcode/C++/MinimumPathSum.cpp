#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() == 0) {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i > 0 && j > 0) {
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                }
                else if (i > 0) {
                    grid[i][j] += grid[i - 1][j];
                }
                else {
                    grid[i][j] += grid[i][j - 1];
                }

            } 
        }
        int y = grid.size() - 1;
        int x = grid[y].size() - 1;
        return grid[y][x];
    }
private:
    int min(int &a, int &b) {
        if (a < b) {
            return a;
        }
        return b;
    }
};
