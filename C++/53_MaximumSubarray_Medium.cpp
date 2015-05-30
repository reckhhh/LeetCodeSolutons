/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Tags: Divide and Conquer, Array, Dynamic Programming
*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int i;
        int maxsofar   = A[0];
        int maxendhere = A[0];
            
        for (i = 1; i < n; ++i)
        {  
            maxendhere = max(maxendhere + A[i], A[i]);  
            maxsofar   = max(maxendhere, maxsofar);  
        }  
        return maxsofar; 
    }
};
