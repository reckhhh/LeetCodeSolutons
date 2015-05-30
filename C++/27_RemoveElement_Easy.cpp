/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 

Tags: Array, Two Pointers
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j;
        int cur;
        
        while (i < n)
        {
            if (A[i] != elem)
            {
                ++i;
                cur = i;
            }
            else
            {
                cur = i;
                j = i + 1;
                while (j < n)
                {
                    A[i++] = A[j++];
                }
                --n;
            }
            i = cur;
        }
        return n;
    }
};
