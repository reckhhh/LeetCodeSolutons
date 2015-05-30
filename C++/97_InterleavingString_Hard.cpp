/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 

Tags: Dynamic Programming, String
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if(size1 + size2 != size3)
            return false;
        bool table[size1 + 1][size2 + 1];
        
        for(int i = 0; i <= size1; ++i) {
            for(int j = 0; j <= size2; ++j) {
                if(i == 0 && j == 0)  table[i][j] = true;
                else if(i == 0)       table[i][j] = table[i][j-1] && (s3[i+j-1] == s2[j-1]);
                else if(j == 0)       table[i][j] = table[i-1][j] && (s3[i+j-1] == s1[i-1]);
                else                  table[i][j] = table[i][j-1] && (s3[i+j-1] == s2[j-1]) || table[i-1][j] && (s3[i+j-1] == s1[i-1]);
            }
        }
        return table[size1][size2];
    }
};
