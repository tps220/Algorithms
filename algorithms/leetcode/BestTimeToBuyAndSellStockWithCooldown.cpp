#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit3(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int size = prices.size(), maxprofit = 0;
        vector<int> buy(size, 0), sell(size, 0);

        buy[1] = max(-prices[0], -prices[1]);
        sell[1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < prices.size(); i++) {
            int price = prices[i];
            //either buy it up, or maintain state
            buy[i] = max(sell[i - 2] - price, buy[i - 1]);
            sell[i] = max(buy[i - 1] + price, sell[i - 1]);
        }
        return sell[size - 1];
    }
private:
    int max(const int a, const int b) {
        if (a > b) {
            return a;
        }
        return b;
    }
    int max(const int a, const int b, const int c) {
        if (a > b) {
            if (a > c) {
                return a;
            }
            return c;
        }
        else if (b > c) {
            return b;
        }
        return c;
    }
};
