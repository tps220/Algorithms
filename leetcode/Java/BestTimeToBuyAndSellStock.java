import java.lang.*;
import java.io.*;

class Solution {
	public int maxProfit(int[] prices) {
		int minPrice = 0;
		int maxProfit = 0;
		for (int i = 0; i < prices.length; i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
			if (prices[i] - minPrice > maxProfit) {
				maxProfit = prices[i] - minPrice;
			}
		}
		return maxProfit;
	}
}