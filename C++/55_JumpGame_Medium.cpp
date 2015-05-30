/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 

Tags: Array, Greedy
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        int val = 0;
        int max = 0;
	
	    for (int i = 0; i < n; ++i) {
	        val = i;
	    	val += A[i];
	    	max = max > val ? max : val;
		    if (max >= n - 1)
			    return true;
			if (i == max)
			    return false;
	    }
    }
};
