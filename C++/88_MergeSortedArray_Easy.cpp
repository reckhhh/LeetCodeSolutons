/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Tags: Array, Two Pointers
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        
        for (int k = m + n - 1; k >= 0; --k)
        {
            if (i < 0)
                A[k] = B[j--];
            else if (j < 0)
                A[k] = A[i--];
            else if (A[i] < B[j])
                A[k] = B[j--];
            else
                A[k] = A[i--];
        }
    }
};
