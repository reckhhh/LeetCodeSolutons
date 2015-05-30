/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Tags: Backtracking, Math
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums(n);
        int pCount = 1;
        for(int i = 0 ; i < n; ++i) {
            nums[i] = i + 1;
            pCount *= i + 1;
        }

        --k;
        for(int i = 0 ; i < n; ++i) {
            pCount /= n - i;
            int selected = k / pCount;
            ans += ('0' + nums[selected]);
            k %= pCount;

            for(int j = selected; j < n - i - 1; ++j)
                nums[j] = nums[j + 1];
        }
        return ans;
    }
};
