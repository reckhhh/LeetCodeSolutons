/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.
Note:

Your solution should be in logarithmic complexity.

Tags: Array, Binary Search
*/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int N = num.size();
        if(N == 0 || N == 1 || num[0] > num[1])
            return 0;
        if(num[N - 1] > num[N - 2])
            return N - 1;
            
        int l = 1, r = N - 2;
        while(l < r) {
            int m = (l + r) / 2;
            if(num[m] > num[m - 1] && num[m] > num[m + 1])
                return m;
            else if(num[m] < num[m + 1])
                l = m + 1;
            else if(num[m] < num[m - 1])
                r = m - 1;
        }
        return l;
    }
};
