/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.

Tags: Array, Dynamic Programming
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int A[row][col];
        
        if(row == 1) {
            for(int j = 0; j < col; ++j) {
                if(obstacleGrid[0][j] == 1)
                    return 0;
            }
            return 1;
        }
        if(col == 1) {
            for(int i = 0; i < row; ++i) {
                if(obstacleGrid[i][0] == 1)
                    return 0;
            }
            return 1;
        }
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1)
            return 0;
            
        for(int i = 0; i < row; ++i)  A[i][0] = 1;
        for(int j = 1; j < col; ++j)  A[0][j] = 1;
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    A[i][j] = 0;
                    if(i == 0) {
                        int m = j;
                        while(m < col)
                            A[0][m++] = 0;
                    }
                    if(j == 0) {
                        int n = i;
                        while(n < row)
                            A[n++][0] = 0;
                    }
                }
            }
        }
        
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                if(obstacleGrid[i][j] != 1)
                    A[i][j] = A[i-1][j] + A[i][j-1];
            }
        }
        return A[row-1][col-1];
    }
};
