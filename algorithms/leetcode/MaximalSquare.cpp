#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector< vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        char result = '0';
        vector< vector<char> > dp(rows + 1, vector<char>(cols + 1, '0'));
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                    if (dp[i][j] > result) {
                        result = dp[i][j];
                    }
                }
            }
        }
        return (int)((result - '0') * (result - '0'));
    }
private:
    char min(char &a, char &b, char &c) {
        if (a < b) {
            if (a < c) {
                return a;
            }
            return c;
        }
        else if (b < c) {
            return b;
        }
        return c;
    }
};
