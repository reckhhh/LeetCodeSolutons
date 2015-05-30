/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Tags: String
*/
class Solution {
public:
    string expendCenter(string s, int start, int end) {
        int l = start, r = end;
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;  ++r;
        }
        return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        string res = s.substr(0, 1);
        for(int i = 0; i < s.size(); ++i) {
            string res1 = expendCenter(s, i, i);
            if(res1.size() > res.size())
                res = res1;
                
            string res2 = expendCenter(s, i, i+1);
            if(res2.size() > res.size())
                res = res2;
        }
        return res;
    }
};
