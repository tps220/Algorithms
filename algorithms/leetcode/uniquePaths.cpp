#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        //initialize array
        int **grid = new int*[m];
        for (int i = 0; i < m; i++) {
            grid[i] = new int[n];
        }

        //create boundary conditions
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            grid[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
            }
        }
        
        int retval = grid[m - 1][n - 1];
        
        //cleanup
        for (int i = 0; i < m; i++) {
            delete grid[i];
        }
        delete grid;
        return retval;
    }        
};
