/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Tags: Dynamic Programming, String
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n == 0)  return m;
        if (m == 0)  return n;
        int A[n + 1][m + 1];
    
        // Step 2
        for (int i = 0; i <= n; ++i)  A[i][0] = i;
        for (int j = 0; j <= m; ++j)  A[0][j] = j;
    
        for (int i = 1; i <= n; ++i) {  // Step 3
            char word1_i = word1[i-1];
            for (int j = 1; j <= m; ++j) {  // Step 4
                char word2_j = word2[j-1];
                int cost = (word1_i == word2_j) ? 0 : 1;  // Step 5
                A[i][j] = min(min(A[i-1][j]+1, A[i][j-1]+1), A[i-1][j-1]+cost);// Step 6
            }
        }
        return A[n][m];  // Step 7
    }
};
