/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Tags: Array, Two Pointers
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int x, y, z;
        for(x = num.size() - 1; x >= 2; --x) {
            if(x < num.size() - 1 && num[x] == num[x + 1])
                continue;
            for(y = 0, z = x - 1; y < z; ) {
                if(y > 0 && num[y] == num[y - 1]) {
                    ++y;
                    continue;
                }
                if(z < x - 1 && num[z] == num[z + 1]) {
                    --z;
                    continue;
                }
                int sum = num[x] + num[y] + num[z];
                if(sum < 0)
                    ++y;
                if(sum > 0)
                    --z;
                if(sum == 0) {
                    vector<int> temp;
                    temp.push_back(num[y]);
                    temp.push_back(num[z]);
                    temp.push_back(num[x]);
                    result.push_back(temp);
                    ++y;
                    --z;
                }
            }
        }
        return result;
    }
};
