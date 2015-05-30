/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 

Tags: Backtracking, String
*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n > 3 || s.empty() || (s[0] == '0' && n > 1) || stoi(s) > 255)
            return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        for(int i = 1; i < n - 2 && i < 4; ++i) {
            for(int j = i + 1; j < n - 1 && j < i + 4; ++j) {
                for(int k = j + 1; k < n && k < j + 4; ++k) {
                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j-i);
                    string s3 = s.substr(j, k-j);
                    string s4 = s.substr(k, n-k);
                    if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                        string temp = s1 + "." + s2 + "." + s3 + "." + s4;
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};
