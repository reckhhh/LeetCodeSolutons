/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)    return 1;
        int A[m][n];
        for(int row = 0; row < m; ++row)  A[row][0] = 1;
        for(int col = 0; col < n; ++col)  A[0][col] = 1;
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                A[i][j] = A[i-1][j] + A[i][j-1];
            }
        }
        return A[m-1][n-1];
    }
};
