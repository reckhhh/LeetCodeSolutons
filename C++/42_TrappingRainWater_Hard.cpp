/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Tags: Array, Stack, Two Pointers
*/
class Solution {
public:
    int trap(int A[], int n) {
        int wholeArea = 0, blocks = 0, left = 0, right = n - 1, height = 0;
        while(left <= right) {
            if(min(A[left], A[right]) > height) {
                wholeArea += (right - left + 1) * (min(A[left], A[right]) - height);
                height = min(A[left], A[right]);
            }
            blocks += (A[left] < A[right]) ? A[left++] : A[right--];
        }
        return wholeArea - blocks;
    }
};
