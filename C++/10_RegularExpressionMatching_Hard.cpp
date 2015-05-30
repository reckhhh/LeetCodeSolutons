/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

Tags: Dynamic Programming, Backtracking, String
*/
class Solution {
public:
    bool matchFirst(const char *s, const char *p) {
        return (*p == *s) || (*p == '.' && *s != '\0');
    }
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0')  return (*s == '\0');
        if(*(p + 1) != '*') {
            if(!matchFirst(s, p))    return false;
            return isMatch(s + 1, p + 1);
        }
        else {
            if(isMatch(s, p + 2))    return true;
            while(matchFirst(s, p))
                if(isMatch(++s, p + 2))  return true;
        }
    }
};

