/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 

Tags: Array, Greedy
*/
class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int last = 0;   // last longest location
        int curr = 0;   // curr longest location
        
        for(int i = 0; i < n; ++i) {
            if(i > last) {
                last = curr;
                ++step;
            }
            curr = max(curr, i + A[i]);
        }
        return step;
    }
};
