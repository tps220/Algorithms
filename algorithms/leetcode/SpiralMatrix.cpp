#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> > &matrix) {
        if (matrix.size() == 0) {
            return vector<int>();
        }
        vector<int> spiral;
        int rowBegin = 0, colBegin = 0;
        int rowEnd = (int)matrix.size() - 1;
        int colEnd = (int)matrix[0].size() - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; i++) {
                spiral.push_back(matrix[rowBegin][i]);
            }
            for (int i = rowBegin + 1; i <= rowEnd; i++) {
                spiral.push_back(matrix[i][colEnd]);
            }
            if (rowBegin < rowEnd && colBegin < colEnd) {
                for (int i = colEnd - 1; i > colBegin; i--) {
                    spiral.push_back(matrix[rowEnd][i]);
                }
                for (int i = rowEnd; i > rowBegin; i--) {
                    spiral.push_back(matrix[i][colBegin]);
                }
            }
            rowBegin++;
            colBegin++;
            rowEnd--;
            colEnd--;
        }
        return spiral;
    }
};
