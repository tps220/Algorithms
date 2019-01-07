#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
private:
    int min(const int a, const int b) {
        if (a < b) {
            return a;
        }
        return b;
    }
};
