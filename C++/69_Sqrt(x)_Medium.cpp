/*
Implement int sqrt(int x).

Compute and return the square root of x.

Tags: Math, Binary Search
*/
class Solution {
public:
    int sqrt(int x) {
        double ans = x;
        while (fabs(pow(ans, 2) - x) > 0.0001) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }
};
