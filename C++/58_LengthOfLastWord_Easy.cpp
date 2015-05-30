/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 

Tags: String
*/
class Solution {
public:
    bool isAlpha(char c) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            return true;
        else
            return false;
    }
    
    int lengthOfLastWord(const char *s) {
        int len = 0;
        int i   = strlen(s) - 1;
        
        while (!isAlpha(s[i]))
        {
            i -= 1;
            if (i < 0)
                return len;
        }
        
        while (i >= -1)
        {
            if (i >= 0 && isAlpha(s[i--]))
                len += 1;
            else
                return len;
        }
    }
};
