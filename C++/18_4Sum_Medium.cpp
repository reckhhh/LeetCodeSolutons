/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

Tags: Array, Hash Table, Two Pointers
*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int a, b, c, d;
        for(d = num.size() - 1; d >= 3; --d) {
            if(d < num.size() - 1 && num[d] == num[d + 1])
                continue;
            for(c = d - 1; c >= 2; --c) {
                if(c < d - 1 && num[c] == num[c + 1])
                    continue;
                for(a = 0, b = c - 1; a < b; ) {
                    if(a > 0 && num[a] == num[a - 1]) {
                        ++a;
                        continue;
                    }
                    if(b < c - 1 && num[b] == num[b + 1]) {
                        --b;
                        continue;
                    }
                    int sum = num[a] + num[b] + num[c] + num[d];
                    if(sum < target)
                        ++a;
                    if(sum > target)
                        --b;
                    if(sum == target) {
                        vector<int> temp;
                        temp.push_back(num[a]);
                        temp.push_back(num[b]);
                        temp.push_back(num[c]);
                        temp.push_back(num[d]);
                        result.push_back(temp);
                        ++a;
                        --b;
                    }
                }
            }
        }
        return result;
    }
};
