/*
 Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 

Tags: Dynamic Programming, String
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.size(), lenT = T.size();
        if(lenS < lenT)  return 0;
        
        vector<vector<int> > dp(lenT + 1, vector<int>(lenS + 1, 0));
        for(int i = 0; i <= lenS; ++i) {
            dp[0][i] = 1;
        }
        for(int i = 1; i <= lenT; ++i) {
            for(int j = 1; j <= lenS; ++j) {
                dp[i][j] = dp[i][j-1] + (T[i-1] == S[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[lenT][lenS];
    }
};
