/*
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Tags: Dynammic Programming, String
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m != n || s1.empty() || s2.empty())
            return false;
        if(s1 == s2)
            return true;
        
        vector<char> c1, c2;
        for(int i = 0; i < n; ++i) {
            c1.push_back(s1[i]);
            c2.push_back(s2[i]);
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        if(c1 != c2)    return false;
        
        for(int i = 1; i < n; ++i) {
            if( isScramble(s1.substr(0, i), s2.substr(0, i))   && isScramble(s1.substr(i, n-i), s2.substr(i, n-i)) )    return true;
            if( isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i)) )    return true;
        }
        return false;
    }
};
