/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Tags: Array, Binary Search
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int m = (l + r) / 2;
            if(target == A[m])
                return true;
            else if(A[l] < A[m]) {
                if(target >= A[l] && target < A[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if(A[l] > A[m]) {
                if(target > A[m] && target <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
                ++l;
        }
        return false;
    }
};
