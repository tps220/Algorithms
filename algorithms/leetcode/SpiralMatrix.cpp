#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> > &matrix) {
        vector<int> answer;
        if (matrix.size() == 0) {
            return answer;
        }
        int i = 0, j = 0, horizontal = 1, vertical = 0;
        int counter = 0, size = matrix.size() * matrix[0].size();
        for(;;) {
            if (counter == size) {
                break;
            }
            //moving forward
            if (horizontal == 1) {
                if (j == matrix[i].size() - 1 || matrix[i][j + 1] == 0) {
                    horizontal = 0;
                    vertical = 1;
                }
            }
            //moving backward
            else if (horizontal == -1) {
                if (j == 0 || matrix[i][j - 1] == 0) {
                    horizontal = 0;
                    vertical = -1;
                }
            }
            //moving downwards
            else if (vertical == 1) {
                if (i == matrix.size() - 1 || matrix[i + 1][j] == 0) {
                    horizontal = -1;
                    vertical = 0;
                }
            }
            //moving upwards
            else {
                if (i == 0 || matrix[i - 1][j] == 0) {
                    horizontal = 1;
                    vertical = 0;
                }
            }
            answer.push_back(matrix[i][j]);
            matrix[i][j] = 0;
            i += vertical;
            j += horizontal;
            counter++;
        }
        return answer;
    }
};
