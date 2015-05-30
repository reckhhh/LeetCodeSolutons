/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Tags: Hash Table, Bit Manipulation
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int one;
        for (int i = 0; i < n; ++i)
            one ^= A[i];
        return one;
    }
};
