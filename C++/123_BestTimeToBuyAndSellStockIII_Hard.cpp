/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        
        int maxPro = 0;
        vector<int> history;
        vector<int> future;
        history.assign(n, 0);
        future.assign(n, 0);
        
        int minVal = prices[0];
        for(int i = 1; i < n; ++i) {
            minVal     = min(minVal, prices[i]);
            history[i] = max(history[i-1], prices[i] - minVal);
        }
        
        int maxVal = prices[n-1];
        for(int i = n - 2; i >= 0; --i) {
            maxVal    = max(maxVal, prices[i]);
            future[i] = max(future[i+1], maxVal - prices[i]);
            
            maxPro    = max(maxPro, history[i] + future[i]);
        }
        
        return maxPro;
    }
};
