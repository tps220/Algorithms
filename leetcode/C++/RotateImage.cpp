#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector< vector<int> > &matrix) {
        for (int i = 0; i < (int)matrix.size() / 2; i++) {
            for (int j = i; j < (int)matrix[i].size() - i - 1; j++) {
                cycle_swap(matrix, i, j); 
            }
        }
    }
private:
    void cycle_swap(vector< vector<int> > &matrix, int x, int y) {
        int temp = matrix[x][y];
        int size = matrix.size() - 1;
        matrix[x][y] = matrix[size - y][x];
        matrix[size - y][x] = matrix[size - x][size - y];
        matrix[size - x][size - y] = matrix[y][size - x];
        matrix[y][size - x] = temp;
    }
};
