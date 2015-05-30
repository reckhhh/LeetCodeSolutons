/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 

Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int maxProduct(int A[], int n) {
        
    int i;
    int maxCur = A[0], minCur = A[0], maxsofar = A[0];
    int maxTmp, minTmp;

    for (i = 1; i < n; ++i)
    {
        minTmp = minCur;
        maxTmp = maxCur;
        
        minCur = min( min(A[i], maxTmp * A[i]), minTmp * A[i] );
        maxCur = max( max(A[i], maxTmp * A[i]), minTmp * A[i] );
        
        maxsofar = max( maxCur, maxsofar );
    }
    return maxsofar;
    }
};
