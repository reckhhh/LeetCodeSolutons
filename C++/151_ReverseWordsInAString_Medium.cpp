/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.

Tags: String
*/
class Solution {
public:
    void reverseWords(string &s) {
     int     i, j;
     int     begin, end;
     int     len = s.length();
     
     string  word;
     
     // all blanks
     i = 0;
     while (s[i] == ' ')
     {
         i += 1;
         if (s[i] == '\0')
         {
             s = "";
             return;
         }
     }
       
     // otherwise
     i = len - 1;
     while (i >= 0)   
     {
         while(s[i] == ' ')     // skip blanks in tail
         {
             i -= 1;
             if (i < 0)
             {
                 i = 0;
                 break;
             }
         }
         end = i;
         
         while (s[i - 1] != ' ' && i > 0)
             --i;
         begin = i;
         
         for (j = begin; j <= end && s[j] != ' '; ++j)
             word += s[j];
         i -= 1;
         
         // when should add blanks ?
         j = 0;
         while (j < i)
         {
             if (s[j] != ' ')
             {
                word += ' ';
                break;
             }
             ++j;
         }
     }

     s = word;
    }
};
