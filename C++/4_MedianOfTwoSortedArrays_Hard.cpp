/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Tags: Divide and Conquer, Array, Binary Search
*/
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int size = m + n;

	    int median2 = size / 2;
	    int median1 = median2 - 1;

	    double m1, m2;
	    int loc = 0;

	    if (m == 0) 
	    {
		    m2 = B[n / 2];
		    m1 = B[n / 2 - 1];
	    }
	    if (n == 0)
	    {
		    m2 = A[m / 2];
		    m1 = A[m / 2 - 1];
	    }

	    while (loc <= median2 && m != 0 && n != 0)
	    {
		    if (i == m)
		    {
			    if (loc == median1)     m1 = B[j];
			    if (loc == median2)     m2 = B[j];
			    ++j;
			    ++loc;
		    }
		    if (j == n)
		    {
                if (loc == median1)     m1 = A[i];
			    if (loc == median2)     m2 = A[i];
			    ++i;
			    ++loc;
		    }

		    if (A[i] <= B[j] && i < m && j < n)
		    {
			    if (loc == median1)     m1 = A[i];
			    if (loc == median2)     m2 = A[i];
			    ++i;
			    ++loc;
		    }
		    if (A[i] > B[j] && i < m && j < n)
		    {
			    if (loc == median1)     m1 = B[j];
			    if (loc == median2)     m2 = B[j];
			    ++j;
			    ++loc;
		    }
	    }
		return (size % 2 == 0) ? (m1 + m2) / 2.0 : m2;
    }
};
