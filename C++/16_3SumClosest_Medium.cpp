/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Tags: Array, Two Pointers
*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int ret = (target >= 0) ? numeric_limits<int>::max() : numeric_limits<int>::min() + 1;
        for(int x = num.size() - 1; x >= 2; --x) {
            if(x < num.size() - 1 && num[x] == num[x + 1])
                continue;
            for(int y = 0, z = x - 1; y < z; ) {
                if(y > 0 && num[y] == num[y - 1]) {
                    ++y;
                    continue;
                }
                if(z < x - 1 && num[z] == num[z + 1]) {
                    --z;
                    continue;
                }
                int sum = num[x] + num[y] + num[z];
                if(abs(sum - target) < abs(ret - target))   ret = sum;
                if(sum == target)   return target;
                if(sum >  target)   --z;
                if(sum <  target)   ++y;
            }
        }
        return ret;
    }
};

