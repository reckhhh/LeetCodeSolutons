/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

Tags: Dynamic Programming, Backtracking, Greedy, String
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* star = NULL;    // location after '*'
        const char* ss   = s;       // new start location of s when p is '*'
        while(*s) {
            if(*p == '?' || *p == *s)   { ++s; ++p;               continue; } 
            if(*p == '*')               { star = p; ss = s; ++p;  continue; } 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not * , only advancing pattern pointer
            if(star)                    { p = star + 1; s = ++ss; continue; } 

            //current pattern pointer is not star, last patter pointer was not * , characters do not match
            return false;
        }
        
        //check for remaining characters in pattern
        while(*p == '*')                { ++p; }

        return !(*p);  
    }
};
