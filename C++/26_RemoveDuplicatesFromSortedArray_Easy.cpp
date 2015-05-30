/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

Tags: Array, Two Pointers
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 2)
            return n;
        
        int pre = 0, cur = 1;
        while(cur < n) {
            if(A[pre] == A[cur])
                A[pre] = A[cur++];
            else
                A[++pre] = A[cur++];
        }
        return pre + 1;
    }
};
