/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 

Tags: Array, Binary Search
*/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(target < A[0])   return 0;
        if(target > A[n-1]) return n;
        
        int l = 0, r = n - 1, m;
        while(l <= r) {
            m =  l + (r - l) / 2;
            if(A[m] < target)       l = m + 1;
            else if(A[m] > target)  r = m - 1;
            else                    return m;
        }
        return l;
    }
};
