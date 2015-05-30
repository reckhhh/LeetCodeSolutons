/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 

Tags: Dynamic Programming, String
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)  return 0;
        
        vector<int> ans(n+1, 0);
        ans[n]   = 1;
        ans[n-1] = (s[n-1] == '0') ? 0 : 1;
        
        for(int i = n - 2; i >= 0; --i) {
            if(s[i] != '0')
                ans[i] = (stoi(s.substr(i, 2)) <= 26) ? (ans[i+1] + ans[i+2]) : ans[i+1];
        }
        return ans[0];
    }
};
