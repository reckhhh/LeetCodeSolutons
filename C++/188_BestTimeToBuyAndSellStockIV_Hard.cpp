/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags: Dynammic Programming
*/
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if(k >= n / 2)   return quickSolve(prices, n);
        
        // initial the array of zero
        int res[k + 1][n] = {0};
        for(int i = 0; i < n; ++i)  res[0][i] = 0;

        // compute the result
        for(int i = 1; i <= k; ++i) {
            int tmpMax = -prices[0];
            for(int j = 1; j < n; ++j) {
                res[i][j] = max(res[i][j - 1], prices[j] + tmpMax);
                tmpMax    = max(tmpMax, res[i - 1][j - 1] - prices[j]);
            }
        }
        return res[k][n - 1];
    }
    
    int quickSolve(vector<int> &prices, int n) {
        int profit = 0;
        for(int i = 1; i < n; ++i) {
            if(prices[i] > prices[i - 1])   profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
