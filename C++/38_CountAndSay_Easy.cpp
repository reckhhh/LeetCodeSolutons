/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 

Tags: String
*/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)  return "";
        if(n == 1)  return "1";
        
        string res = "1";
        string tmp;
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < res.size(); ++j) {
                int cnt = 1;
                while((j < res.size() - 1) && (res[j] == res[j + 1])) {
                    ++cnt;
                    ++j;
                }
                tmp += std::to_string(cnt) + res[j];
            }
            res = tmp;
            tmp = "";
        }
        return res;
    }
};
