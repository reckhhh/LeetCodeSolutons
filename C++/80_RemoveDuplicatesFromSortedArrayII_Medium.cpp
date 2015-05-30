/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 

Tags: Array, Two Pointers
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 3)
            return n;
            
        int pre = 0, cur = 1, len = 1;
        while(cur < n) {
            if(len <= 2) {
                if(A[pre] != A[cur]) {
                    len = 1;
                    A[++pre] = A[cur++];
                } 
                else {
                    if(len < 2) {
                        ++pre;
                    }
                    ++len;
                    A[pre] = A[cur++];
                }
            }
            else {
                if(A[pre] == A[cur])
                    ++cur;
                else {
                    len = 1;
                    A[++pre] = A[cur++];
                }
            }
        }
        return pre + 1;
    }
};
