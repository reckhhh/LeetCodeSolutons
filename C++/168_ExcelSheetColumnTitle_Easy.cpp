/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

Tags: Math
*/
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n) {
            res += (--n % 26) + 'A';
            n /= 26;
        }
        return string(res.rbegin(), res.rend());
    }
};
