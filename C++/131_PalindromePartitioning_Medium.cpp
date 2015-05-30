/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

Tags: Backtracking
*/
class Solution {
public:
    bool isPalindrome(string str) {
        int l = 0, r = str.size() - 1;
        while(l < r) {
            if(str[l] != str[r]) {
                return false;
            }
            ++l, --r;
        }
        return true;
    }
    void help(string s, int start, vector<string> &temp, vector<vector<string> > &res) {
        if(start == s.size()) {
            res.push_back(temp);
            return;
        }
        for(int i = start; i < s.size(); ++i) {
            string str = s.substr(start, i - start + 1);    // start location: "start", size = "i - start + 1"
            if(isPalindrome(str)) {
                temp.push_back(str);
                help(s, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> temp;
        help(s, 0, temp, res);
        return res;
    }
};
