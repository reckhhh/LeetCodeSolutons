/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 

Tags: Two Pointers, String
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int i, j, value;
     
        if (s.length() == 1)
            return true;
     
        for (i = 0; s[i] == ' ' || s[i] == '\0'; ++i) {
            if (s[i] == '\0')
                return true;
        }
        for (i = 0, j = s.length() - 1; i < j; ++i, --j) {
            while (!isalnum(s[i])) {
                ++i;
                if(i == j)
                    return true;
            }
            while ( !isalnum(s[j])) {
                --j;
                if(j == i)
                    return true;
            }
         
            value = s[i] - s[j];
            if ( !(value == 0 || value == 32 || value == -32) )
                return false;
        }
        return true;
    }
};
