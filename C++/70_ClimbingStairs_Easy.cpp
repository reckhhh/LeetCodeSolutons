/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

Tags: Dynamic Programming
*/
class Solution {
public:
    int climbStairs(int n) {
        int ppre = 2;
        int pre  = 3;
        int cur;
        
        if (n == 0 || n == 1 || n == 2 || n == 3)
            return n;
            
        for(int i = 4; i <= n; ++i)
        {
            cur  = ppre + pre;
            ppre = pre;
            pre  = cur;
        }
            
        return cur;
    }
};
