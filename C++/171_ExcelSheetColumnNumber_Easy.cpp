/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Tags: Math
*/
class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;
        for(int i = 0; i < s.size(); ++i)
            num = num * 26 + (s[i] - 'A' + 1) ;
            
        return num;
    }
};
