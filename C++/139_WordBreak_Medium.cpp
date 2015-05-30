/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". 

Tags: Dynamic Programming
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[len] = true;
        
        for(int start = len - 1; start >= 0; --start) {
            for(int end = start; end < len; ++end) {
                string sub = s.substr(start, end - start + 1);
                if(dict.find(sub) != dict.end() && dp[end + 1] == true) {
                    dp[start] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
