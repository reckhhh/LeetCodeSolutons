/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 

Tags: Array, Binary Search
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = 0, r = n - 1;
        vector<int> result(2, -1);
        
        // find the most left target
        while(l < r) {
            int m = (l + r) / 2;
            if(A[m] < target)
                l = m + 1;
            else
                r = m;
        }
        if(A[l] != target)
            return result;
        else
            result[0] = l;
        
        // find the most right target
        r = n - 1;
        while(l < r) {
            int m = (l + r) / 2 + 1;
            if(A[m] > target)
                r = m - 1;
            else
                l = m;
        }
        result[1] = r;
        return result;
    }
};
