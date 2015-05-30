/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 

Tags: Array
*/
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        int ans = 0;
        for(auto i : num) {
            if(map[i] != 0)  continue;
            ans = max(ans, map[i] = map[i + map[i+1]] = map[i - map[i-1]] = map[i+1] + map[i-1] + 1);
        }
        return ans;
    }
};
